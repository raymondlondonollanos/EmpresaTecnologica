#include "Clientes.h"
#include <string>
#include <iostream>

namespace clientes
{
	//Constructor que inicializa 
	Clientes::Clientes(std::string_view nombre, std::string_view apellido , int ID , short num_items )
		: Clientes::Clientes{nombre , " " , apellido ,
		" " , ID , num_items}
	{
		

		
	}

	//Constructor delegado
	Clientes::Clientes(std::string_view p_nombre, std::string_view s_nombre, std::string_view p_apellido, std::string_view s_apellido, int ID , short num_items)
		: m_primr_nombre{p_nombre} , m_seg_nombre{s_nombre} ,
		m_primr_apellido{m_primr_apellido}, m_seg_apellido{s_apellido} ,
	m_ID{ ID }
	{
		m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item];
	}

	Clientes::~Clientes()
	{
		//memoria deasignada
		if(m_vect_nom_prod_in_clien_ptr != nullptr)
		{
			
			delete[] m_vect_nom_prod_in_clien_ptr;
		    m_vect_nom_prod_in_clien_ptr = nullptr;
		    std::cout << "\nMemoria Limpiada ";
		}

	}

	

	Clientes::Clientes(const Clientes& m_clientes)
		: m_primr_nombre{ m_clientes.m_primr_nombre }, m_seg_nombre{ m_clientes.m_seg_nombre },
		m_primr_apellido{m_clientes.m_primr_apellido} , m_seg_apellido{m_clientes.m_seg_apellido},
		m_ID{m_clientes.m_ID},
		m_num_item{ m_clientes.m_num_item }
	{

		m_vect_nom_prod_in_clien_ptr = new std::string[m_clientes.m_num_item];

	}

	Clientes& Clientes::operator=(const Clientes& m_clientes)
	{
		// Evitar la autoasignación
		if (this == &m_clientes) {
			return *this;
		}

		// Liberar la memoria actual
		delete[] m_vect_nom_prod_in_clien_ptr;

		// Copiar los valores de los miembros
		m_primr_nombre = m_clientes.m_primr_nombre;
		m_seg_nombre = m_clientes.m_seg_nombre;
		m_primr_apellido = m_clientes.m_primr_apellido;
		m_seg_apellido = m_clientes.m_seg_apellido;
		m_num_item= m_clientes.m_num_item;

		// Copia profunda del array dinámico
		m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item];
		std::copy(m_clientes.m_vect_nom_prod_in_clien_ptr,
			m_clientes.m_vect_nom_prod_in_clien_ptr + m_num_item,
			m_vect_nom_prod_in_clien_ptr);

		return *this;
	}

	void Clientes::agregar_items()
	{

		//Falta el otr while para la validacion de empleado

		//Elementos a utilizar para el agregado de items
		std::string* copy_vector;
		std::string* temp_vector;
		short cant_item_copyV{ 0 };
		short cant_item_tempV{ 0 };
		char validador{ 'n' };

		std::cout << "Ingrese el numero de items: ";
		//m_num_items pasa como una variable objeto implicito
		//Por eso no se inicializa
		std::cin >> m_num_item;


		//Validando el ciclo de la entrada de datos para el ingreso de items
		do {

			//garantizamos que siempre entre primero aqui para inicializar el vect_imput_items
			if (validador != 's')
			{

				//creamos un string local para almacenar datos ingresados por usuario
				std::string item_local;

				//Inicalizamos el puntero vect_imput_items
				m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item];

				//Ingresar items y almaecenarlos en el vect_nom
				for (std::size_t i{ 0 }; i < m_num_item; ++i)
				{
					std::cout << "\nIngrese el item: ";
					std::cin >> item_local;

					m_vect_nom_prod_in_clien_ptr[i] = item_local;
				}

			}

		} while (validador == 's');

	}

    


	void Clientes::mostrar_item() const
	{
		std::cout << "\nLista de items\n";
		for (std::size_t i{ 0 }; i < m_num_item; i++)
		{
			std::cout << "\n" << m_vect_nom_prod_in_clien_ptr[i];
		}
		
	}

}



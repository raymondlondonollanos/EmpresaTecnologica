#include "Clientes.h"
#include <string>
#include <iostream>
#include <algorithm>

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
	m_ID{ ID }, m_num_item{num_items}
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
		char validador= 'n';

		



		//Validando el ciclo de la entrada de datos para el ingreso de items
		do {
			
			//garantizamos que siempre entre primero aqui para inicializar el vect_imput_items
			if (validador != 's')
			{
				
				//creamos un string local para almacenar datos ingresados por usuario
				std::string item_local;

				std::cout << "Ingrese el numero de items: " << m_num_item;

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
			else
			{

				//validacion que no sea nulo el vector m_vec_nom
				if (m_vect_nom_prod_in_clien_ptr != nullptr)
				{
		
					cant_item_copyV = m_num_item;

					copy_vector = new std::string[cant_item_copyV];

					//almacenamos la informacion transitoria en este vector copy
					std::copy(m_vect_nom_prod_in_clien_ptr, m_vect_nom_prod_in_clien_ptr+ m_num_item, copy_vector);

					//borramos el puntero y lo declaramos nulo
					delete[] m_vect_nom_prod_in_clien_ptr;
					m_vect_nom_prod_in_clien_ptr = nullptr;

					//Le solicitamos al usuario nuevamente el numero de item a ingresar
					std::cout << "\nIngresa el numero de items: ";
					std::cin >> cant_item_tempV;

					//inicializamos el vector temporal para tener la otra lista almacenada
					temp_vector = new std::string[cant_item_tempV];

					//solicitamos ingresar los items al usuario por consola
					for (std::size_t i{0}; i < cant_item_tempV ; ++i)
					{
						//inicio for

						//variable local for
						std::string item_local_dos;

						std::cout << "\nIngresa los items: ";
						std::cin >> item_local_dos;

						temp_vector[i] = item_local_dos;

						//fin for
					}

					//realizamos la suma del valor total almacenado en ambos vec y copiamos a num_item
					m_num_item = cant_item_tempV + cant_item_copyV;

					//Inicializamos el vector para almacenar los items almacenados en lso dos vectores
					m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item];

					//empezamos el copiado del primer vector copy
					for (std::size_t i{0}; i < cant_item_copyV ; ++i)
					{
						//inicio del for
						m_vect_nom_prod_in_clien_ptr[i] = copy_vector[i];
						
						//fin ciclo for
					}

					//Empezamos el copiado de segundo vector tem secuencialmente en el vector m_vect
					for (std::size_t i {0}; i<cant_item_tempV ; ++i)
					{
						//inico for
						m_vect_nom_prod_in_clien_ptr[cant_item_copyV + i] = temp_vector[i];

						//fin ciclo for
					}

					delete[] copy_vector;
					copy_vector = nullptr;

					delete[] temp_vector;
					temp_vector = nullptr;

				}
				

			}

			//salimimos del if que valida que m_num_vect no sea nulo
					//Verificamos antes si el usuario desea agregar mas itema o salir
			std::cout << "\nDeseas agregar mas items: s/n";
			std::cin >> validador;

			//limpiar el buffer para evitar caracteres estranos
			std::cin.ignore();

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



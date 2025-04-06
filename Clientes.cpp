#include "Clientes.h"
#include <string>
#include <iostream>

namespace clientes
{
	//Constructor que inicializa 
	Clientes::Clientes(std::string_view nombre, std::string_view apellido , int ID , short num_items)
		: Clientes::Clientes{nombre , " " , apellido ,
		" " , ID , num_items}
	{
		

		
	}

	//Constructor delegado
	Clientes::Clientes(std::string_view p_nombre, std::string_view s_nombre, std::string_view p_apellido, std::string_view s_apellido, int ID , short num_items)
		: m_primr_nombre{p_nombre} , m_seg_nombre{s_nombre} ,
		m_primr_apellido{m_primr_apellido}, m_seg_apellido{s_apellido} ,
		m_ID{ ID } , m_num_item_input_cliente {
		num_items
	}

	{
		m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item_input_cliente];
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
		m_num_item_input_cliente{ m_clientes.m_num_item_input_cliente }
	{
		
			
		
			// Copia profunda del array dinámico
			m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item_input_cliente];

			std::copy(m_clientes.m_vect_nom_prod_in_clien_ptr,
				m_clientes.m_vect_nom_prod_in_clien_ptr + m_num_item_input_cliente,
				m_vect_nom_prod_in_clien_ptr);

		

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
		m_num_item_input_cliente = m_clientes.m_num_item_input_cliente;

		// Copia profunda del array dinámico
		m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item_input_cliente];
		std::copy(m_clientes.m_vect_nom_prod_in_clien_ptr,
			m_clientes.m_vect_nom_prod_in_clien_ptr + m_num_item_input_cliente,
			m_vect_nom_prod_in_clien_ptr);

		return *this;
	}

	void Clientes::agregar_items(std::string* &items)
	{
		//se copiar el puntero en el puntero items
		std::copy(items , items + m_num_item_input_cliente, m_vect_nom_prod_in_clien_ptr);
	}

        const std::string* pedir_items_vec_copy()
        {
                std::cout << "\nIngresa el numero de items a comprar en nuestras empresa de tecnologia: ";
		std::cin >> num_items;

		clientes::Clientes cl{p_nombre , p_apellido , ID, num_items};

		//Inicializamos el puntero para almacenar los items ingresado por el usuario
		m_copy_vect_items_ptr = new std::string[num_items];

		for (std::size_t i{ 0 }; i < m_copy_vect_items_ptr; i++)
		{
			//creacion de variable local string 
			std::string items_local{};
			
			std::cout << "\nIngresa el items " << (i + 1) 
				<< ": ";
			std::cin >> items_local;
			m_copy_vect_items_ptr[i] = items_local;
		}

		cl.agregar_items(items_ptr);
            
		
	}


	void Clientes::mostrar_item() const
	{
		std::cout << "\nLista de items\n";
		for (std::size_t i{ 0 }; i < m_num_item_input_cliente; i++)
		{
			std::cout << "\n" << m_vect_nom_prod_in_clien_ptr[i];
		}
		
	}

}



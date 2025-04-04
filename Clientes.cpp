#include "Clientes.h"
#include <string>
#include <iostream>

namespace clientes
{
	//Constructor que inicializa 
	Clientes::Clientes(std::string_view nombre, std::string_view apellido , short num_items)
		: Clientes::Clientes{nombre , " " , apellido , " " , num_items}
	{
		

		
	}

	//Constructor delegado
	Clientes::Clientes(std::string_view p_nombre, std::string_view s_nombre, std::string_view p_apellido, std::string_view s_apellido, short num_items)
		: m_primr_nombre{p_nombre} , m_seg_nombre{s_nombre} ,
		m_primr_apellido{m_primr_apellido}, m_seg_apellido{s_apellido} ,
		m_num_item_input_cliente{num_items}

	{
		m_vect_nom_prod_in_clien_ptr = new std::string[m_num_item_input_cliente];
	}

	Clientes::~Clientes()
	{
		//memoria deasignada
		delete[] m_vect_nom_prod_in_clien_ptr;
		m_vect_nom_prod_in_clien_ptr = nullptr;
		std::cout << "Memoria Limpiada ";
	}

	

	Clientes::Clientes(const Clientes& m_clientes)
		: m_primr_nombre{ m_clientes.m_primr_nombre }, m_seg_nombre{ m_clientes.m_seg_nombre },
		m_primr_apellido{m_clientes.m_primr_apellido} , m_seg_apellido{m_clientes.m_seg_apellido},
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

	const std::string* Clientes::mostrar_item() const
	{
		return m_vect_nom_prod_in_clien_ptr;
	}

}



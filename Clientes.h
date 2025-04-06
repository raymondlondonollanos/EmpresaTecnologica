
//protectores de encabezado para evitar colisiones de nombres, recordar que pragma once, no funciona en todos
// los compiladores. Pragma once, ifndef define y namespace
#pragma once
#ifndef  CLIENTES_H
# define  CLIENTES_H

//Agregamos la libreria string que no permite trabajar con la strint estilo c, literales estilo, literales string, string_view
#include <string>
#include <vector>
#include <string_view>


namespace clientes
{
	class Clientes
	{
	public:

		//Declaracion de constructor por defecto
		Clientes() = default;


		//Declaracion de construccion, que pide dos argumentos de tipo string_view
		Clientes(std::string_view p_nombre, std::string_view p_apellido, int ID, short num_items);


		Clientes(std::string_view p_nombre, std::string_view  s_nombre ,
			std::string_view p_apellido, std::string_view s_apellido , int ID , short num_items);


		//Eliminacion del constructor de copias, no queremos asignarle a otro cliente las propiiedades de uno ya existente por eso lo eliminamos
		Clientes(const Clientes& m_clientes) ;

		Clientes& operator=(const Clientes& m_clientes);

		

		//Funciones setter
		void agregar_items(std::string*  &items);


                const std::string* pedir_items_vec_copy();



		//mostar los items sin modificarlos
		void mostrar_item()const;

		//desctrutir
		~Clientes();

		// Declaracion e inicializacion de dos variables miembros en la que obtendremos el nombre
		//delcliente
	private:
		//std::string es mucho mas seguro que utilizar cadenas estilo c. Char
		std::string m_primr_nombre{};
		std::string m_seg_nombre{};
		std::string m_primr_apellido{};
		std::string m_seg_apellido{};
		//Los datos van a iniciar desde 0 y seran siempre valores positivos, se utiliza short para ahorrar
		//espacio en almacenamiento, ya que osn dos bytes
		short m_num_item_input_cliente{};

		//variable miembro documento de identidad
		int m_ID{};
		//Declaramos un puntero string para probar las diferencias en 
                //funcionalidades con el sd::vector
		std::string *m_vect_nom_prod_in_clien_ptr;
                std::string *m_copy_vect_items_ptr;

		
	};

}


#endif // ! 



#include <iostream>
#include <vector>
#include "Clientes.h"
#include <string>
#include <limits>

int main()
{
#if 0
	std::string name{ "Raymond " };
	std::string apellido{ "Londono" };
	short num{ 5 };

	clientes::Clientes cl{ name, apellido, num , 12};

	std::string items[] = { "mouse ", "teclado ", "monitor ", "Torre " , "Disco duro" };

	std::string* items_ptr = items;

	cl.agregar_items(items_ptr);

	const std::string* mostar_items(cl.mostrar_item());


	for (std::size_t i{ 0 }; i < 5; i++)
	{
		std::cout << "Mostrando items " << *(mostar_items + i) << '\n';
	}
	
#endif

	//Ahora vamos a probar como pedir la informacion al cliente e ir la ingresando{};
	std::string p_nombre{};
	std::string s_nombre{};
	std::string p_apellido{};
	std::string s_apellido{};
	int ID{};
	short num_items{};
	std::string* items_ptr{ nullptr };


	//obtencion de datos personales del cliente

		std::cout << "\nIngresa tu primer nombre: ";
		std::cin >> p_nombre;

		std::cout << "\nIngresa tu segundo nombre, sino tiene presiona enter: ";
		std::cin >> s_nombre;

		std::cout << "\nIngresa tu primer apellido: ";
		std::cin >> p_apellido;

		std::cout << "\nIngresa tu segundo apellido, sino tiene presiona enter: ";
		std::cin >> s_apellido;

		std::cout << "\nIngresa tu numero de CC: ";
		std::cin >> ID;

		//limpieza de buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
		std::cout << "\nIngresa el numero de items a comprar en nuestras empresa de tecnologia: ";
		std::cin >> num_items;

		clientes::Clientes cl{p_nombre , p_apellido , ID, num_items};

		//Inicializamos el puntero para almacenar los items ingresado por el usuario
		items_ptr = new std::string[num_items];

		for (std::size_t i{ 0 }; i < num_items; i++)
		{
			//creacion de variable local string 
			std::string items_local{};
			
			std::cout << "\nIngresa el items " << (i + 1) 
				<< ": ";
			std::cin >> items_local;

			items_ptr[i] = items_local;
		}

		cl.agregar_items(items_ptr);

		//limpiamos el puntero, que no necesitamos 
		delete[] items_ptr;

		//declara nulo por buenas practicas
		items_ptr = nullptr;

		cl.mostrar_item();

	return 0;
}
#include <iostream>
#include <vector>
#include "Clientes.h"
#include <string>

int main()
{

	std::string name{ "Raymond " };
	std::string apellido{ "Londono" };
	short num{ 5 };

	clientes::Clientes cl{ name, apellido, num };

	std::string items[] = { "mouse ", "teclado ", "monitor ", "Torre " , "Disco duro" };

	std::string* items_ptr = items;

	cl.agregar_items(items_ptr);

	const std::string* mostar_items(cl.mostrar_item());


	for (std::size_t i{ 0 }; i < 5; i++)
	{
		std::cout << "Mostrando items " << *(mostar_items + i) << '\n';
	}
	

	return 0;
}
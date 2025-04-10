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




        std::string* items_ptr;
        std::string* copy_items_ptr;
        std::string* tem_copy_items_ptr;
        char validador = 'n';
        int num_impu_user;
        int temp_copy = 0;


        std::cout << "Ingresa la cantidad de items ";
        std::cin >> num_impu_user;

        do {



            if ('s' == validador)
            {

                temp_copy = num_impu_user;

                copy_items_ptr = new std::string[temp_copy];

                std::copy(items_ptr, items_ptr + num_impu_user,
                    copy_items_ptr);
                std::cout << "funciona hasta quiw\n";


                delete[] items_ptr;
                items_ptr = nullptr;


                std::cout << "Ingresa la cantidad de items ";
                std::cin >> num_impu_user;

                tem_copy_items_ptr = new std::string[num_impu_user];

                items_ptr = new std::string[num_impu_user + temp_copy];


                for (int i = 0; i < num_impu_user; ++i)
                {
                    std::string item;
                    std::cout << "Ingresa los items: ";
                    std::cin >> item;

                    tem_copy_items_ptr[i] = item;

                }

                for (int i = 0; i < temp_copy; ++i)
                {

                    items_ptr[i] = copy_items_ptr[i];

                }

                for (int i = 0; i < num_impu_user; ++i)
                {

                    items_ptr[temp_copy + i] = copy_items_ptr[i];

                }


            }
            else
            {
                items_ptr = new std::string[num_impu_user];

                for (int i = 0; i < num_impu_user; ++i)
                {
                    std::string item;
                    std::cout << "Ingresa los items: ";
                    std::cin >> item;

                    items_ptr[i] = item;

                }

            }


            std::cout << "Deseas agregar mas item s/n";
            std::cin >> validador;

        } while ('s' == validador);


        for (int i = 0; i < temp_copy + num_impu_user; ++i)
        {

            std::cout << " vector : " << items_ptr[i];

        }

     

	

		

	return 0;
}

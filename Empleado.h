#pragma once

#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>


namespace empleado
{
	class Empleado
	{
	public:
		//constructor por defecto para pruebas
		Empleado() = default;

		//Constructor de copias
		Empleado(const Empleado& m_empelado);

		Empleado& operator=(const Empleado& m_empleado);

		//metodos set
		//copiados de los items de la clase clientes a la clase empleados
		void set_clientes_items();

		void set_total_unidades();

		void set_costo_por_unidad();

		void set_costo_por_paquete();


		//metodos get
		const std::string* get_clientes_item() const;

		const std::string* get_total_unidades() const;

		const std::string* get_costo_unidad() const;

		const std::string* get_costo_apquete() const;


		//Destructor
		~Empleado();


	private:
		std::string* clientes_items = nullptr;
		std::size_t* total_unidades = nullptr;
		std::size_t* costo_unidad = nullptr;
		std::size_t* costo_paquete = nullptr;

		//arreglo multidimensional que contendra todo la informacion de la compra y el cliente
		std::string** Total_infor_cliente = nullptr;

	};

}


#endif // !EMPLEADO_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:35:39 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/11/24 19:30:02 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files/files.hpp"
#include "debug/debug.hpp"
#include "search/search.hpp"

void leaks (void)
{
	system("leaks -q quickathon");
}

std::string get_input(void)
{
	std::string	input;
	getline(std::cin, input);
	if (input.empty())
		return ("");
	return (input);
}

void call_id (product *prod, int size)
{
	std::string code_input;
	std::cout << "Introduzca el codigo de barras del producto"<< std::endl;
	code_input = get_input();
	search_by_id(prod,size,code_input);
}

void call_type(product *prod, int size)
{
	std::string code_input;
	int type;

	std::cout << "Introduzca el tipo de producto"<< std::endl;
	code_input = get_input();
	type = transform_input_type(code_input);
	if (type != -1)
		search_by_type(prod,size,type);
	else
		std::cout << "Data is not valid"<< std::endl;
}	



int main(void)
{
	atexit(leaks);
    std::string code_input;
	std::string direction_input = "./data/Data.csv";
	product *prod;
	int	size;
    
	size = file_size(direction_input);
	if (size <= 0)
		std::cout << "Direccion vacia // saliendo del programa"<< std::endl;
	else
	{
		prod = (product *)calloc(sizeof(product), size);
		prod = read_file(direction_input,prod);
		do
		{
			std::cout << "Busqueda por ID (1)/ Busqueda por Tipo (2) / Exit (3)"<< std::endl;
			code_input = get_input();
			if (code_input == "1")
				call_id(prod, size);
			else if (code_input == "2")
				call_type(prod, size);
			else if (code_input == "3")
				break;
			else
				std::cout << "Comando no entendible"<< std::endl;
		} 
		while (code_input != "exit");
		
		delete prod;
	}
	
    return(0);
}
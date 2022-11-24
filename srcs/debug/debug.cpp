/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:34:33 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/11/24 18:34:44 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "debug.hpp"

void show_objects(product *prod, int size)
{
	for (int i = 0; i < size;i++)
	{
		std::cout << "- - - - - - - " << std::endl;
		std::cout << prod[i] << std::endl;
	}
	std::cout << "- - - - - - - " << std::endl;
	return;
}
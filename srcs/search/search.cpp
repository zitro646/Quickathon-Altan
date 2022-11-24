/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:38:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/11/24 19:35:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search.hpp"

void search_by_id(product *prod, int size, std::string id)
{
    std::cout << "searching product ... with id -> " << id << std::endl;
	for (int i = 0; i < size;i++)
	{
        if (prod[i].get_id() == id)
        {
		    std::cout << "Data is "<< std::endl << prod[i];
            return;
        }
	}
    std::cout << "Product ID not found ... " << std::endl;
    return ;
}

int type_alike(int type)
{
    int lines[7] = {PAPER,GLASS,PLASTIC,ORGANIC,REST,SPECIAL,ERROR};
    for (int i = 0;i < 7;i++)
        if (lines[i] == type)
            return (1);
    return (-1);
}

// std::string lines_str[7] = {PAPER_STR,GLASS_STR,PLASTIC_STR,ORGANIC_STR,REST_STR,SPECIAL_STR,ERROR_STR};
void search_by_type(product *prod, int size, int type)
{
    std::cout << "searching products by type ... " << type << std::endl;
    
    for (int i = 0; i < size;i++)
    {
        if (prod[i].get_type() == type)
        {
            std::cout << "- - - - - -" << std::endl;
            std::cout << prod[i];
        }
    }
     
    
    
    return ;
}
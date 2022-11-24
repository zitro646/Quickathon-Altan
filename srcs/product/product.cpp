/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/11/09 13:34:23 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "product.hpp"

product::product( void ) : id("") , data("") , type(7)
{
  return ;
}

product::product( std::string i , std::string dat , int ty ) : id(i) , data(dat) , type(ty)
{
  return ;
}

product::product( const product & var ) {
  *this = var;
  return ;
}

product::~product( void ) {
  return ;
}

product &product::operator=(const product &tmp)
{
  this->id = tmp.id;
  this->data = tmp.data;
  this->type = tmp.type;
  return(*this);
}

int transform_input_type(std::string str)
{
	std::string lines_str[7] = {PAPER_STR,GLASS_STR,PLASTIC_STR,ORGANIC_STR,REST_STR,SPECIAL_STR,ERROR_STR};
	for (int i = 0;i < 7;i++)
	{
		if (str == lines_str[i])
			return (i + 1);
	}
	return (-1);
}

std::string rerverse_transform_input_type(int type)
{
	std::string lines_str[7] = {PAPER_STR,GLASS_STR,PLASTIC_STR,ORGANIC_STR,REST_STR,SPECIAL_STR,ERROR_STR};
  int lines[7] = {PAPER,GLASS,PLASTIC,ORGANIC,REST,SPECIAL,ERROR};
	for (int i = 0;i < 7;i++)
	{
		if (type == lines[i])
			return (lines_str[i]);
	}
	return ("ERROR");
}

std::ostream &operator<<(std::ostream& os, const product &tmp)
{
	os << "id           |     " << tmp.get_id() << std::endl;
	os << "data         |     " << tmp.get_data() << std::endl;
	os << "type         |     " << rerverse_transform_input_type(tmp.get_type()) << std::endl << std::endl;
	return (os);
}


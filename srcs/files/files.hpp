/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:35:28 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/11/24 18:35:28 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "../product/product.hpp"

int         file_size(std::string dir);
product     *read_file(std::string dir,product *products);
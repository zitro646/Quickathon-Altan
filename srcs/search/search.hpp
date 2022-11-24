/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:38:00 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/11/24 19:20:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../product/product.hpp"

void search_by_id(product *prod, int size, std::string id);
void search_by_type(product *prod, int size, int type);
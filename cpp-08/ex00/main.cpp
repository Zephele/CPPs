/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:42:06 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/27 17:43:43 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main(void){

	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::vector<int>::iterator it;
	it = easyfind(v, 3);
	std::cout << *it << std::endl;
	try {
		it = easyfind(v, 6);
		std::cout << *it << std::endl;
	}catch (const std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
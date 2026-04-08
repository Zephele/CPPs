/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:05:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/08 13:43:13 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(){
	Data		data1;
	uintptr_t	ptr;
	Data*		data2 = NULL;

	data1.raw = 10;
	ptr = Serializer::serialize(&data1);
	data2 = Serializer::deserialize(ptr);

	std::cout << "Data 1 address: " << &data1 << std::endl;
	std::cout << "Data 2 address: " << data2 << std::endl;
	std::cout << "Pointers are equal: " << std::boolalpha << (data2 == &data1) << std::endl;
	std::cout << "Data 1 raw: " << data1.raw << std::endl;
	std::cout << "Data 2 raw: " << data2->raw << std::endl;
	return (0);
}
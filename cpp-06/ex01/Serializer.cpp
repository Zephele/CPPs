/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:05:54 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/08 13:27:07 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout << "Serializer default constructor called!" << std::endl;
}

Serializer::Serializer(const Serializer& other){
	std::cout << "Serializer copy constructor called!" << std::endl;
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other){
	std::cout << "Copy assignment operator Serializer called!" << std::endl;
	(void)other;
	return (*this);
}

Serializer::~Serializer(){
	std::cout << "Serializer destructor called!" << std::endl;
}


uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

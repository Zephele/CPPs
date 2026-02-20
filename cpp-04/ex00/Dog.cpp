/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:52 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 16:58:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy constructor Dog called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		Animal::operator=(other);
		std::cout << "Copy assigment operator Dog called!" << std::endl;
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called!" << std::endl;
}

std::string	Dog::getType(){
	return (this->type);
}

void	Dog::makeSound(){
	std::cout << "Some generic sound" << std::endl;
}
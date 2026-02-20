/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:45 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 17:48:04 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& other){
	type = other.type;
	std::cout << "Copy constructor Animal called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other){
		type = other.type;
		std::cout << "Copy assignment operator Animal called" << std::endl;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called!" << std::endl;
}

std::string	Animal::getType() const{
	return (this->type);
}

void	Animal::makeSound() const{
	std::cout << "Some generic sound" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:31:47 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/02 16:38:36 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type(""){
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	type = other.type;
	std::cout << "Copy constructor WrongAnimal called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other){
		type = other.type;
		std::cout << "Copy assignment operator WrongAnimal called" << std::endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

std::string	WrongAnimal::getType() const{
	return (this->type);
}

void	WrongAnimal::makeSound() const{
	std::cout << "Some generic sound" << std::endl;
}
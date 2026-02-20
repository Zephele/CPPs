/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 17:48:07 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Copy constructor Cat called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		std::cout << "Copy assignment operator Cat called" << std::endl;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called!" << std::endl;
}

std::string	Cat::getType() const{
	return (this->type);
}

void	Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}
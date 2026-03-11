/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/09 13:40:50 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called!" << std::endl;
	catBrain = new Brain;
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat copy constructor called!" << std::endl;
	catBrain = new Brain(*other.catBrain);
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other){
		std::cout << "Cat copy assignment operator called" << std::endl;
		delete catBrain;
		catBrain = new Brain(*other.catBrain);
		type = other.type;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called!" << std::endl;
	delete catBrain;
}

std::string	Cat::getType() const{
	return (this->type);
}

void	Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}

Brain* Cat::getBrain() const{
    return catBrain;
}
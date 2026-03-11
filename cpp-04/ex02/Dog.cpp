/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:52 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/09 13:41:16 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called!" << std::endl;
	dogBrain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called!" << std::endl;
	dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other){
		std::cout << "Dog copy assignment operator called!" << std::endl;
		delete dogBrain;
		dogBrain = new Brain(*other.dogBrain);
		type = other.type;
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called!" << std::endl;
	delete dogBrain;
}

std::string	Dog::getType() const{
	return (this->type);
}

void	Dog::makeSound() const{
	std::cout << "Woof woof!" << std::endl;
}

Brain* Dog::getBrain() const{
    return dogBrain;
}
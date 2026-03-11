/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:31:45 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/02 16:48:39 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	std::cout << "Copy constructor WrongCat called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other){
		WrongAnimal::operator=(other);
		std::cout << "Copy assignment operator WrongCat called" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called!" << std::endl;
}

std::string	WrongCat::getType() const{
	return (this->type);
}

void	WrongCat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}
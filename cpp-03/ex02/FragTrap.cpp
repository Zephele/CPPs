/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:34:21 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 13:32:57 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	this->hP = 100;
	this->eP = 100;
	this->aD = 30;
	std::cout << "FragTrap default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->hP = 100;
	this->eP = 100;
	this->aD = 30;
	std::cout << "FragTrap constructor called!" << std::endl;
}


FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "Copy assignment operator FragTrap called" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "Destructor FragTrap called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << " requests a positive high-five! ✋" << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (this->hP == 0){
		std::cout << "FragTrap " << this->name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->eP == 0){
		std::cout << "FragTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	this->eP--;
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->aD << " points of damage!" << std::endl;
}

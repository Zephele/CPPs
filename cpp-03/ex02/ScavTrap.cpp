/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:59:49 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 11:18:11 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	this->hP = 100;
	this->eP = 50;
	this->aD = 20;
	std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->hP = 100;
	this->eP = 50;
	this->aD = 20;
	std::cout << "Constructor ScavTrap called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){	
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->hP == 0){
		std::cout << "ScavTrap " << this->name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->eP == 0){
		std::cout << "ScavTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	this->eP--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->aD << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
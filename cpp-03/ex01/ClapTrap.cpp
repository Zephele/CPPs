/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:09:45 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 11:17:14 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	// Constructor
ClapTrap::ClapTrap() : name(""), hP(10), eP(10), aD(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hP(10), eP(10), aD(0) {
	std::cout << "Constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hP(other.hP), eP(other.eP), aD(other.aD) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		this->name = other.name;
		this->hP = other.hP;
		this->eP = other.eP;
		this->aD = other.aD;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

	// Destructor
ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

	// Moviments
void ClapTrap::attack(const std::string& target){
	if (this->hP == 0){
		std::cout << "ClapTrap " << this->name << " is dead and can't attack!" << std::endl;
		return;
	}
	if (this->eP == 0){
		std::cout << "ClapTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	this->eP--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->aD << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hP == 0){
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	if (amount >= (unsigned int)this->hP){
		this->hP = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and dies!" << std::endl;
	}
	else
	{
		this->hP -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hP == 0){
		std::cout << "ClapTrap " << this->name << " is dead and can't be repaired!" << std::endl;
		return;
	}
	if (this->eP == 0){
		std::cout << "ClapTrap " << this->name << " has no energy to repair!" << std::endl;
		return;
	}
	this->eP--;
	this->hP += amount;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " hit points!" << std::endl;
}

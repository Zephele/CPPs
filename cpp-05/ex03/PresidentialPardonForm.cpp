/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:54:08 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 16:51:34 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), target("Default"){
	std::cout << "PresidentialPardonForm default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("PresidentialPardonForm", 25, 5), target(target){
	std::cout << "PresidentialPardonForm constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), target(other.target){
	std::cout << "PresidentialPardonForm copy constructor called!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	std::cout << "Copy assignment operator PresidentialPardonForm called!" << std::endl;
	if (this != &other){
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor called!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	this->checkExecution(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox!" << std::endl; 
}
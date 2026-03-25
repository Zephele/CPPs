/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:54:13 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 17:36:11 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {
	std::cout << "RobotomyRequestForm default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target){
	std::cout << "RobotomyRequestForm copy constructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	std::cout << "Copy assignment operator RobotomyRequestForm called!" << std::endl;
	if (this != &other){
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	this->checkExecution(executor);

	static bool	seed = false;
	if (!seed){
		std::srand(std::time(NULL));
		seed = true;
	}
	std::cout << "BZZZZZZZZ... DRRRRRRR..." << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}
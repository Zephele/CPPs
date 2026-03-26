/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:14:39 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/26 18:24:05 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
	std::cout << "Intern default constructor called!" << std::endl;
}

Intern::Intern(const Intern& other){
	std::cout << "Intern copy constructor called!" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	std::cout << "Copy assignment operator Intern called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern(){
	std::cout << "Intern destructor called!" << std::endl;
}

AForm*	Intern::createRobotomyRequest(const std::string& target){
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createShrubberyCreation(const std::string& target){
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createPresidentialPardon(const std::string& target){
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target){

	const std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*actions[3])(const std::string&) = {&Intern::createRobotomyRequest,
		&Intern::createPresidentialPardon, &Intern::createShrubberyCreation};

	for (int i = 0; i < 3; i++){
		if (formName == forms[i]){
			std::cout << "Intern creates " << formName << std::endl;
			return((this->*actions[i])(target)); 
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}
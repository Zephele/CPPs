/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:54:19 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 17:37:04 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {
	std::cout << "ShrubberyCreationForm default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "ShrubberyCreationForm constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {
	std::cout << "ShrubberyCreationForm copy constructor called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment operator ShrubberyCreationForm called!" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	this->checkExecution(executor);
	std::ofstream   fileOut;
	fileOut.open((target + "_shrubbery").c_str());
	if (!fileOut.is_open()){
		std::cout << "The output file cannot be opened" << std::endl;
		return ;
	} else {
		fileOut << "    oxoxoo    ooxoo" << std::endl;	
		fileOut << "  ooxoxo oo  oxoxooo" << std::endl;	
		fileOut << " oooo xxoxoo ooo ooox" << std::endl;	
		fileOut << " oxo o oxoxo  xoxxoxo" << std::endl;	
		fileOut << "  oxo xooxoooo o ooo" << std::endl;	
		fileOut << "    ooo\\oo\\  /o/o" << std::endl;	
		fileOut << "        \\  \\/ /" << std::endl;	
		fileOut << "         |  |" << std::endl;
		fileOut << "         | D|" << std::endl;
		fileOut << "         |  |" << std::endl;
		fileOut << "         |  |" << std::endl;
		fileOut << "  ______/____\\____" << std::endl;
	}
	fileOut.close();
}
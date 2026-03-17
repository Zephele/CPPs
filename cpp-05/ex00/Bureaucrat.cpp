/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:53:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/17 17:46:16 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Carlos"), grade(75){
	std::cout << "Bureaucrat default constructor called!" << std::endl;
}
			
Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade){
	std::cout << "Bureaucrat constructor with args called!" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}
			
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade){
	std::cout << "Bureaucrat copy constructor called!" << std::endl;
}
			
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	std::cout << "Copy assignment operator Bureaucrat called" << std::endl;
	if (this != &other)
		grade = other.grade;
	return (*this);
	
}
		
Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called!" << std::endl;
}

// //Incrementos

void	Bureaucrat::incrementGrade(){
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}
void	Bureaucrat::decrementGrade(){
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}
			
//Getters

std::string Bureaucrat::getName() const{return(this->name);}
			
int Bureaucrat::getGrade() const{return(this->grade);}

//Exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade too low!";
}

//insertion operator

std::ostream& operator<<(std::ostream& output, const Bureaucrat& clas) {
	output << clas.getName() << ", burocrata com classificação " << clas.getGrade();
	return (output);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:53:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 17:35:27 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Carlos"), grade(75){
	std::cout << "Bureaucrat default constructor called!" << std::endl;
}
			
Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade){
	std::cout << "Bureaucrat constructor called!" << std::endl;
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

const std::string& Bureaucrat::getName() const{return(this->name);}
			
int Bureaucrat::getGrade() const{return(this->grade);}

//Exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

//insertion operator

std::ostream& operator<<(std::ostream& output, const Bureaucrat& clas) {
	output << clas.getName() << ", bureaucrat grade " << clas.getGrade() << ".";
	return (output);
}

void Bureaucrat::signForm(AForm& form){
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const{
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << getName() << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
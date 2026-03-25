/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:50:34 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 13:45:32 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name(""), sign(false), gradeToSign(50), gradeToExecute(50){
	std::cout << "AForm default constructor called!" << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign,
	const int gradeToExecute): name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){					
	std::cout << "AForm constructor called!" << std::endl;
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other): name(other.name), sign(other.isSigned()),
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){
	std::cout << "AForm copy constructor called!" << std::endl;		
}

AForm& AForm::operator=(const AForm& other){
	std::cout << "Copy assignment operator AForm called" << std::endl;
	if (this != &other){
		sign = other.isSigned();
	}
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm destructor called!" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed!";
}

const std::string& AForm::getName() const{
	return (name);
}

bool	AForm::isSigned() const{
	return (sign);
}

int AForm::getGradeToSign() const{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const{
	return (gradeToExecute);	
}

void AForm::beSigned(Bureaucrat& other){
	if (other.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->sign = true;
}

void AForm::checkExecution(Bureaucrat const & executor) const {
	if (!this->isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& output, const AForm& clas){
	output << "AForm '" << clas.getName() << "'"
		<< ", signed: " << (clas.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << clas.getGradeToSign()
		<< ", grade to execute: " << clas.getGradeToExecute();
	return (output);
}

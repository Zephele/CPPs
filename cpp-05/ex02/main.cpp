/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:53:52 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 17:32:26 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	Bureaucrat intern("Intern", 150);
	Bureaucrat mid("Mid", 70);
	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm shrub("casa");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "============== SIGN TESTS ==============" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;
	
	intern.signForm(shrub);
	mid.signForm(shrub);
	mid.signForm(robot);
	boss.signForm(pardon);

	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "============ EXECUTE TESTS =============" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "============ ShrubberyCreationForm =============" << RESET << std::endl;
	std::cout << std::endl;
	try {
		intern.executeForm(shrub);
	} catch (const std::exception& e) {
		std::cout << "Intern execute failed: " << e.what() << std::endl;
	}
	try {
		mid.executeForm(shrub);
	} catch (const std::exception& e) {
		std::cout << "Mid execute failed: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << BOLD << YELLOW << "============ RobotomyRequestForm =============" << RESET << std::endl;
	std::cout << std::endl;
	try {
		mid.executeForm(robot);
	} catch (const std::exception& e) {
		std::cout << "Mid execute failed: " << e.what() << std::endl;
	}
	try {
		boss.executeForm(robot);
	} catch (const std::exception& e) {
		std::cout << "Boss execute failed: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << BOLD << YELLOW << "============ PresidentialPardonForm =============" << RESET << std::endl;
	std::cout << std::endl;
	try {
		boss.executeForm(pardon);
	} catch (const std::exception& e) {
		std::cout << "Boss execute failed: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << BOLD << YELLOW << "============ Destructors =============" << RESET << std::endl;
	std::cout << std::endl;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:53:52 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/17 18:02:59 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(){
	
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "=   Test with GradeTooHighException   =" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;
	try {
		Bureaucrat Carlos("Carlos", 0);
	} catch (const std::exception& e) {
   		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "=    Test with GradeTooLowException   =" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;
	try {	
		Bureaucrat Carlos1("Carlos", 151);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "=       Teste without exceptions      =" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;
	try {
		Bureaucrat Carlos2("Carlos", 75);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "=         Teste with Decrement        =" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;
	Bureaucrat Carlos2("Carlos", 149);
	std::cout << Carlos2 << std::endl;
	try{ Carlos2.decrementGrade(); } catch (const std::exception&e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << Carlos2 << std::endl;
	try{ Carlos2.decrementGrade(); } catch (const std::exception&e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << Carlos2 << std::endl;

	std::cout << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << BOLD << GREEN << "=         Teste with Increment        =" << RESET << std::endl;
	std::cout << BOLD << GREEN << "========================================" << RESET << std::endl;
	std::cout << std::endl;
	Bureaucrat Kaua("Kaua", 2);
	std::cout << Kaua << std::endl;
	try { Kaua.incrementGrade(); } catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << Kaua << std::endl;
	try { Kaua.incrementGrade(); } catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << Kaua << std::endl;
	std::cout << std::endl;
}
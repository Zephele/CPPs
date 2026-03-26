/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:53:52 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/26 18:19:50 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main() {
	Bureaucrat boss("Boss", 1);
	Intern intern;

	const std::string names[4] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
		"unknown form"
	};

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "\n--- Testing: " << names[i] << " ---" << std::endl;
		AForm* form = intern.makeForm(names[i], "target42");
		if (form == NULL)
		{
			std::cout << "Creation failed as expected for invalid name." << std::endl;
			continue;
		}

		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	return (0);
}
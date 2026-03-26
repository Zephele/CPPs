/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:14:46 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/26 18:16:35 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	createRobotomyRequest(const std::string& target);
		AForm*	createShrubberyCreation(const std::string& target);
		AForm*	createPresidentialPardon(const std::string& target);
		AForm*	makeForm(std::string formName, std::string target);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:53:48 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/17 17:52:39 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BOLD	 "\033[1m"

class Bureaucrat{

	private :
		const std::string	name;
		int					grade;

	public :
		//Builders + Destructor
			Bureaucrat();
			Bureaucrat(const std::string &name, int grade);
			Bureaucrat(const Bureaucrat &other);
			Bureaucrat& operator=(const Bureaucrat &other);
			~Bureaucrat();
		//Incrementos
      		void	incrementGrade();
      		void	decrementGrade();
		//Exception class
			class GradeTooHighException : public std::exception{
				public:
					virtual const char* what() const throw();
			};
			class GradeTooLowException : public std::exception {
				public:
					virtual const char* what() const throw();	
			};
		
		//Getters
			const std::string& getName() const;
			int getGrade() const;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& clas);

#endif

 
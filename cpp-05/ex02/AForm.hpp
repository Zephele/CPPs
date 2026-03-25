/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:50:43 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/25 13:45:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		AForm();
		AForm(const std::string& name, 
			const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw(); 
		};
		class FormNotSignedException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		const std::string& getName() const;
		bool	isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat& other);
		virtual void execute(Bureaucrat const & executor) const = 0;

	protected:
		void checkExecution(Bureaucrat const & executor) const;
	
};

std::ostream& operator<<(std::ostream& output, const AForm& clas);

#endif
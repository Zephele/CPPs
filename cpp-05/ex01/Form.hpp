/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:24:53 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/18 09:43:46 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form();
		Form(const std::string& name, 
			const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw(); 
		};

		const std::string& getName() const;
		bool	isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat& other);
	
};

std::ostream& operator<<(std::ostream& output, const Form& clas);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:39:59 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/11 14:22:33 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact {

	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_PhoneNumber;
		std::string	_DarkestSecret;

	public:
		Contact(void);
		Contact(const std::string &fn,
				const std::string &ln,
				const std::string &nn,
				const std::string &pn,
				const std::string &ds);
		// ~Contact(void);
		void	PrintIndex(void) const;
		void	PrintContact(int i) const;
};

#endif
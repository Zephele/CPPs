/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:39:55 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/12 17:11:36 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"
#include "includes/PhoneBook.hpp"
#include <sstream>

Contact::Contact(void)
	: _FirstName(""), _LastName(""), _NickName(""),
		_PhoneNumber(""), _DarkestSecret("") {}

//Builder
Contact::Contact(const std::string &fn,const std::string &ln,
	const std::string &nn,const std::string &pn,const std::string &ds) {
	this->_FirstName = fn;
	this->_LastName = ln;
	this->_NickName = nn;
	this->_PhoneNumber = pn;
	this->_DarkestSecret = ds;
}

static std::string FormatField(const std::string &s) {
	if (s.size() > 10)
		return s.substr(0, 9) + ".";
	std::string pad(10 - s.size(), ' ');
	return pad + s;
}

void Contact::PrintIndex(void) const{
	std::cout << "#===========================================#" << std::endl;
	std::cout << "#==INDEX===|===NAME===|==L_NAME==|=NICKNAME=#" << std::endl;
	std::cout << "#===========================================#" << std::endl;
}

void Contact::PrintContact(int i) const{
	std::stringstream ss;

	ss << (i + 1);
	std::cout << "|" << FormatField(ss.str());
	std::cout << "|" << FormatField(this->_FirstName);
	std::cout << "|" << FormatField(this->_LastName);
	std::cout << "|" << FormatField(this->_NickName) << "|" << std::endl;
	std::cout << "#==========|==========|==========|==========#" << std::endl;
}

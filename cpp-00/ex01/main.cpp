/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:50:14 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/13 10:39:27 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Contact.hpp"
#include "includes/PhoneBook.hpp"
#include <cctype>

static void	print_menu(void){
	std::cout << std::endl;
	std::cout << "===========================================\n";
	std::cout << "=============PHONEBOOK COMMANDS============"  << std::endl;
	std::cout << "===========================================\n";
	std::cout << " {ADD}" "\t   Save a new contact" << std::endl;
	std::cout << " {SEARCH}" "  Display a specific contact" << std::endl;
	std::cout << " {EXIT}" "\t   Clear and close the phonebook" << std::endl;
	std::cout << "===========================================\n"  << std::endl;
	std::cout << "What you want to do? : ";
}

static std::string	trim(const std::string &s) {
	size_t	start = 0;
	while (start < s.size() && std::isspace(s[start]))
		++start;
	size_t	end = s.size();
	while (end > start && std::isspace(s[end - 1]))
		--end;
	return (s.substr(start, end - start));
}

static bool readNonEmpty(std::string &out, const std::string &prompt) {
	for (;;) {
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return false;
		if (!trim(out).empty())
			return true;
		std::cout << "Empty input. Please try again.\n";
	}
}

int	main()
{
	PhoneBook	phonebook;
	std::string input;

	while(true)
	{
		print_menu();
		if (!std::getline(std::cin, input)){
			break;
		}
		if (input == "ADD"){
			std::string fn, ln, nn, pn, ds;
			if (!readNonEmpty(fn, "Please, type the First Name: ")) break;
			if (!readNonEmpty(ln, "Please, type the Last Name: ")) break;
			if (!readNonEmpty(nn, "Please, type the Nickname: ")) break;
			if (!readNonEmpty(pn, "Please, type the Phone Number: ")) break;
			if (!readNonEmpty(ds, "Please, type the Darkest Secret: ")) break;

			phonebook.Add(Contact(trim(fn), trim(ln), trim(nn), trim(pn), trim(ds)));
		}
		else if (input == "SEARCH"){phonebook.PrintAll();}
		else if (input == "EXIT"){break;}
		else
			std::cout << "Undefinied Command, Try again" << std::endl;
	}
}

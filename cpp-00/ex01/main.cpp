/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:50:14 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/17 13:04:30 by ratanaka         ###   ########.fr       */
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

static std::string	Trim(const std::string &s) {
	size_t	start = 0;
	while (start < s.size() && std::isspace(s[start]))
		++start;
	size_t	end = s.size();
	while (end > start && std::isspace(s[end - 1]))
		--end;
	return (s.substr(start, end - start));
}

static bool ReadNonEmpty(std::string &out, const std::string &prompt) {
	for (;;) {
		std::cout << prompt;
		if (!std::getline(std::cin, out))
			return false;
		if (!Trim(out).empty())
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
			if (!ReadNonEmpty(fn, "Please, type the First Name: ")) break;
			if (!ReadNonEmpty(ln, "Please, type the Last Name: ")) break;
			if (!ReadNonEmpty(nn, "Please, type the Nickname: ")) break;
			if (!ReadNonEmpty(pn, "Please, type the Phone Number: ")) break;
			if (!ReadNonEmpty(ds, "Please, type the Darkest Secret: ")) break;

			phonebook.Add(Contact(Trim(fn), Trim(ln), Trim(nn), Trim(pn), Trim(ds)));
		}
		else if (input == "SEARCH"){
			phonebook.PrintAll();
			std::string index;
			std::getline(std::cin, index);
			phonebook.IndexPrint(index, phonebook.GetSize());
		}
		else if (input == "EXIT"){break;}
		else
			std::cout << "Undefinied Command, Try again" << std::endl;
	}
}

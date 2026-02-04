/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:46:59 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/17 13:04:03 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
	: size(0), next(0) {}

void	PhoneBook::Add(const Contact &c) {
	contacts[next] = c;
	next = (next + 1) % 8;
	if (size < 8) ++size;
}

void PhoneBook::PrintAll() const {
	contacts->PrintIndex();
	for (int i = 0; i < size; ++i)
		contacts[i].PrintContact(i);
	std::cout << "\nType the index: ";
}

void	PhoneBook::IndexPrint(const std::string &index, int size) const{
	std::cout << "\n";

	if (index == "1" && size >= 1)
		contacts[0].PrintContactIndex();
	else if (index == "2" && size >= 2)
		contacts[1].PrintContactIndex();
	else if (index == "3" && size >= 3)
		contacts[2].PrintContactIndex();
	else if (index == "4" && size >= 4)
		contacts[3].PrintContactIndex();
	else if (index == "5" && size >= 5)
		contacts[4].PrintContactIndex();
	else if (index == "6" && size >= 6)
		contacts[5].PrintContactIndex();
	else if (index == "7" && size >= 7)
		contacts[6].PrintContactIndex();
	else if (index == "8" && size >= 8)
		contacts[7].PrintContactIndex();
	else
		std::cout << "There's no contact in this Index or its a invalid index";
}

int	PhoneBook::GetSize(){
	return (this->size);
}
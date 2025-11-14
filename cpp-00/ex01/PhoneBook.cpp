/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:46:59 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/12 17:11:42 by ratanaka         ###   ########.fr       */
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
}

int	PhoneBook::GetSize(){
	return (this->size);
}
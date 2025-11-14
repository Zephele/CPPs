/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:31:33 by ratanaka          #+#    #+#             */
/*   Updated: 2025/11/14 17:20:16 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook{

	private:
		Contact	contacts[8];
		int		size;
		int		next;
	public:
		PhoneBook(void);
		void	Add(const Contact &c);
		void	PrintAll() const;
		void	IndexPrint(const std::string &index) const;
		int		GetSize();
};

#endif
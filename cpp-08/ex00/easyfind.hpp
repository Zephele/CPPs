/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 11:42:02 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/27 17:43:34 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class NothingFound : public std::exception {
	public :
		virtual const char* what() const throw() {return "No matches found.";}
};

template<typename T>
typename T::iterator easyfind(T& firstParam, int secondParam){
	typename T::iterator it;
	for(it = firstParam.begin(); it != firstParam.end(); it++){
		if (*it == secondParam)
			return (it);
	}
	throw NothingFound();
}

#endif
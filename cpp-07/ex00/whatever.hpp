/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:45:03 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/09 13:16:36 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b){
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T& a, T& b){
	return (a < b) ? a : b;
}

template <typename T>
T max(T& a, T& b){
	return (a > b) ? a : b;
}

#endif
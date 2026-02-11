/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:30:18 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/11 14:00:12 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	fix_point = 0;
}

Fixed::Fixed(const Fixed& clas){
	std::cout << "Copy constructor called" << std::endl;
	fix_point = clas.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& clas2){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clas2)
		fix_point = clas2.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const{
	return (this->fix_point);
}

void	Fixed::setRawBits( int const raw ){
	this->fix_point = raw;	
}
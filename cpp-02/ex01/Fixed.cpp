/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:30:18 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/11 17:12:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	fix_point = 0;
}

Fixed::Fixed(const Fixed& clas){
	std::cout << "Copy constructor called" << std::endl;
	fix_point = clas.getRawBits();
}

Fixed::Fixed(const	int ci){
	const int	fixedValue = ci << this->bits;
	this->setRawBits(fixedValue);
}

Fixed::Fixed(const float cf){
	const int	fixedValue = roundf(cf * (1 << this->bits));
	this->setRawBits(fixedValue);
}

// Desconstructors

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// Getter

int		Fixed::getRawBits( void ) const{
	return (this->fix_point);
}

// Setter

void	Fixed::setRawBits( int const raw ){
	this->fix_point = raw;	
}

// Public Methods

float Fixed::toFloat( void ) const{
	return (static_cast<float>(this->fix_point) / (1 << this->bits));
}

int Fixed::toInt( void ) const{
	const	int	convertToInt = this->fix_point >> this->bits;
	return (convertToInt);
}

// Overloaded Operators

std::ostream& operator<<(std::ostream& output, const Fixed& clas){
	output << clas.toFloat();
	return (output);
}

Fixed&	Fixed::operator=(const Fixed& clas2){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clas2)
		fix_point = clas2.getRawBits();
	return *this;
}
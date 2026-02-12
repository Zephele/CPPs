/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:30:18 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/12 13:48:31 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed(){
	fix_point = 0;
}

Fixed::Fixed(const Fixed& clas){
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

Fixed&	Fixed::operator=(const Fixed& clas){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clas)
		fix_point = clas.getRawBits();
	return *this;
}

// Compare Operators

bool	Fixed::operator>(const Fixed& clas) const{
	return(this->fix_point > clas.fix_point);
}

bool	Fixed::operator<(const Fixed& clas) const{
	return(this->fix_point < clas.fix_point);
}

bool	Fixed::operator>=(const Fixed& clas) const{
	return(this->fix_point >= clas.fix_point);
}

bool	Fixed::operator<=(const Fixed& clas) const{
	return(this->fix_point <= clas.fix_point);
}

bool	Fixed::operator==(const Fixed& clas) const{
	return(this->fix_point == clas.fix_point);
}

bool	Fixed::operator!=(const Fixed& clas) const{
	return(this->fix_point != clas.fix_point);
}

// Arithmetic Operators

Fixed	Fixed::operator+(const	Fixed& clas) const{
	return Fixed(this->toFloat() + clas.toFloat());
}

Fixed	Fixed::operator-(const	Fixed& clas) const{
	return Fixed(this->toFloat() - clas.toFloat());	
}

Fixed	Fixed::operator*(const	Fixed& clas) const{
	return Fixed(this->toFloat() * clas.toFloat());
}

Fixed	Fixed::operator/(const	Fixed& clas) const{
	return Fixed(this->toFloat() / clas.toFloat());
}

// Incremental Operators

Fixed&	Fixed::operator++(){
	this->fix_point++;
	return (*this);
}
	
Fixed	Fixed::operator++(int){
	Fixed tmp(*this);
	this->fix_point++;
	return (tmp);
}

Fixed&	Fixed::operator--(){
	this->fix_point--;
	return (*this);
}
	
Fixed	Fixed::operator--(int){
	Fixed tmp(*this);
	this->fix_point--;
	return (tmp);
}

// Static Methods
			
Fixed& Fixed::min(Fixed& a, Fixed& b){
	return (a < b) ? a : b;
}
			
const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b) ? a : b;
}
			
Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a > b) ? a : b;
}
			
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b) ? a : b;
}
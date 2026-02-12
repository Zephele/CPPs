/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:30:20 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/12 13:33:15 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{

	private:
		int					fix_point;
		const static int	bits = 8;
	public:
		// Constructors
			Fixed();
			Fixed(const	int ci);
			Fixed(const float cf);
			Fixed(const Fixed& clas);
			
		// Desconstructors
			~Fixed();

		// Overloaded Operators
			Fixed&	operator=(const Fixed& clas);
			
			// Compare Operators
				bool	operator>(const Fixed& clas) const;
				bool	operator<(const Fixed& clas) const;
				bool	operator>=(const Fixed& clas) const;
				bool	operator<=(const Fixed& clas) const;
				bool	operator==(const Fixed& clas) const;
				bool	operator!=(const Fixed& clas) const;

			// Arithmetic Operators
				Fixed	operator+(const	Fixed& clas) const;
				Fixed	operator-(const	Fixed& clas) const;
				Fixed	operator*(const	Fixed& clas) const;
				Fixed	operator/(const	Fixed& clas) const;

			// Incremental Operators
				Fixed&	operator++();		
				Fixed	operator++(int);	
				Fixed&	operator--();		
				Fixed	operator--(int);	

		// Static Methods
			static	Fixed& min(Fixed& a, Fixed& b);
			static	const Fixed& min(const Fixed& a, const Fixed& b);
			static	Fixed& max(Fixed& a, Fixed& b);
			static	const Fixed& max(const Fixed& a, const Fixed& b);
				
		// Public Methods
			float toFloat( void ) const;
			int toInt( void ) const;

		// Setter
			void	setRawBits( int const raw );

		// Getter
			int		getRawBits( void ) const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& clas);

#endif
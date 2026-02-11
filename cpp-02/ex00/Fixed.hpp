/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:30:20 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/11 13:55:43 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{

	private:
		int					fix_point;
		const static int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& clas);
		Fixed&	operator=(const Fixed& clas2);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};


#endif
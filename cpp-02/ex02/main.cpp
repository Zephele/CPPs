/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 10:30:24 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/12 13:55:18 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int main( void ) {
// 	std::cout << "=== Teste Constructores ===" << std::endl;
// 	Fixed a;
// 	Fixed b( 5 );
// 	Fixed c( 3.14f );
// 	Fixed d( b );
	
// 	std::cout << "a (default): " << a << std::endl;
// 	std::cout << "b (int 5): " << b << std::endl;
// 	std::cout << "c (float 3.14): " << c << std::endl;
// 	std::cout << "d (copy de b): " << d << std::endl;

// 	std::cout << "\n=== Teste Operadores de Comparacao ===" << std::endl;
// 	std::cout << "b > c: " << (b > c) << std::endl;
// 	std::cout << "b < c: " << (b < c) << std::endl;
// 	std::cout << "b >= c: " << (b >= c) << std::endl;
// 	std::cout << "b <= c: " << (b <= c) << std::endl;
// 	std::cout << "b == c: " << (b == c) << std::endl;
// 	std::cout << "b != c: " << (b != c) << std::endl;

// 	std::cout << "\n=== Teste Operadores Aritmeticos ===" << std::endl;
// 	std::cout << "b + c = " << (b + c) << std::endl;
// 	std::cout << "b - c = " << (b - c) << std::endl;
// 	std::cout << "b * c = " << (b * c) << std::endl;
// 	std::cout << "b / c = " << (b / c) << std::endl;

// 	std::cout << "\n=== Teste Pre-incremento ===" << std::endl;
// 	Fixed e( 1.5f );
// 	std::cout << "e = " << e << std::endl;
// 	std::cout << "++e = " << ++e << std::endl;
// 	std::cout << "e = " << e << std::endl;

// 	std::cout << "\n=== Teste Pos-incremento ===" << std::endl;
// 	Fixed f( 2.0f );
// 	std::cout << "f = " << f << std::endl;
// 	std::cout << "f++ = " << f++ << std::endl;
// 	std::cout << "f = " << f << std::endl;

// 	std::cout << "\n=== Teste Pre-decremento ===" << std::endl;
// 	Fixed g( 3.5f );
// 	std::cout << "g = " << g << std::endl;
// 	std::cout << "--g = " << --g << std::endl;
// 	std::cout << "g = " << g << std::endl;

// 	std::cout << "\n=== Teste Pos-decremento ===" << std::endl;
// 	Fixed h( 4.0f );
// 	std::cout << "h = " << h << std::endl;
// 	std::cout << "h-- = " << h-- << std::endl;
// 	std::cout << "h = " << h << std::endl;

// 	std::cout << "\n=== Teste min e max ===" << std::endl;
// 	Fixed i( 10.5f );
// 	Fixed j( 7.2f );
// 	std::cout << "i = " << i << ", j = " << j << std::endl;
// 	std::cout << "Fixed::max(i, j) = " << Fixed::max(i, j) << std::endl;
// 	std::cout << "Fixed::min(i, j) = " << Fixed::min(i, j) << std::endl;

// 	std::cout << "\n=== Teste min e max com const ===" << std::endl;
// 	Fixed const k( 15.75f );
// 	Fixed const l( 8.25f );
// 	std::cout << "k (const) = " << k << ", l (const) = " << l << std::endl;
// 	std::cout << "Fixed::max(k, l) = " << Fixed::max(k, l) << std::endl;
// 	std::cout << "Fixed::min(k, l) = " << Fixed::min(k, l) << std::endl;

// 	return 0;
// }
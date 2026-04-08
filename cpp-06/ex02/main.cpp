/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:51:30 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/08 15:08:04 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(){
	Base* base;

	base = generate();
	std::cout << "Pointer identify: " << std::endl;
	identify(base);
	Base& base1 = *base;
	std::cout << "Reference identify: " << std::endl;
	identify(base1);
	delete base;
	std::cout << "Pointer null identify: " << std::endl;
	Base* base2 = NULL;
	identify(base2);

	return 0;
}
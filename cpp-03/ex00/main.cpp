/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:09:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/09 12:52:59 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap bot("Shrek");
	
	std::cout << "ATACK" << std::endl;
	for (int i = 0; i <= 2; i++)
		bot.attack("Burro");
	std::cout << std::endl;
	
	std::cout << "DEFENSE" << std::endl;
	for (int i = 0; i <= 2; i++)
		bot.takeDamage(5);
	std::cout << std::endl;

	std::cout << "REPAIR" << std::endl;
	for (int i = 0; i <= 2; i++)
		bot.beRepaired(20);
	std::cout << std::endl;
	
	return (0);
}
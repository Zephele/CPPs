/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:09:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 11:18:53 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap bot("Wall-e");
	
	std::cout << std::endl;	
	bot.guardGate();
	std::cout << std::endl;
	
	std::cout << "ATACK" << std::endl;
	for (int i = 0; i <= 2; i++)
	bot.attack("Robocop");
	std::cout << std::endl;
	
	std::cout << "DEFENSE" << std::endl;
	for (int i = 0; i <= 2; i++)
	bot.takeDamage(10);
	std::cout << std::endl;

	std::cout << "REPAIR" << std::endl;
	for (int i = 0; i <= 2; i++)
			bot.beRepaired(20);
	std::cout << std::endl;
	
	return (0);
}
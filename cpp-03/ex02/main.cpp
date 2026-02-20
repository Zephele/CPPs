/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:09:50 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/20 13:37:59 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	FragTrap bot("Gumball");
	
	std::cout << std::endl;	
	bot.highFivesGuys();
	std::cout << std::endl;
	
	std::cout << "ATACK" << std::endl;
	for (int i = 0; i <= 2; i++)
	bot.attack("Darwin");
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
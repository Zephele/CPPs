/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:06:18 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/03 09:37:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << std::endl;
    Zombie *zombie;
    zombie = newZombie("Carlos");
    zombie->announce();
    delete zombie;
    std::cout << std::endl;
    
    std::cout << std::endl;
    randomChump("Isaac");
    std::cout << std::endl;
    return (0);
}
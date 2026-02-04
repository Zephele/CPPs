/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:47:31 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 14:00:37 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int numZombies = 3;
    
    Zombie  *zombies = zombieHorde(numZombies, "Jorge");
    for (int i = 0; i < numZombies; i++){
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}
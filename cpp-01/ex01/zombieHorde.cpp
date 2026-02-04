/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:47:23 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 13:06:37 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie *zombies;
    if (N <= 0)
        return (NULL);
    zombies = new Zombie[N];
    for(int i = 0; i < N; i++){
        zombies[i].setName(name);
    }
    return (zombies);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:47:29 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/03 09:37:21 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
    this->name = "";
}

Zombie::Zombie(std::string name){
    this->name = name;
}

void    Zombie::announce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
    this->name = name;
}

Zombie::~Zombie(void){
    std::cout << this->name << " was destroyed." << std::endl;
}
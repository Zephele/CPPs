/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:05:59 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 15:23:57 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void    HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
}

HumanB::HumanB(const std::string& name):name(name),weapon(NULL){
}

void    HumanB::attack(void){
    if (this->weapon == NULL)
        std::cout << this->name << " attacks with their hands" << '\n';
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << '\n';
}
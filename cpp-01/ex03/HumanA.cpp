/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:05:54 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 15:01:35 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon):name(name),weapon(weapon) {
}

void    HumanA::attack(void){
    std::cout << this->name << " attacks with their " << this->weapon.getType() << '\n';
}
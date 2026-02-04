/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:06:04 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 14:55:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponName)
    : type(weaponName)
{
}

const std::string& Weapon::getType(void) const
{
    return (this->type);
}

void    Weapon::setType(const std::string& type)
{
    this->type = type;
}


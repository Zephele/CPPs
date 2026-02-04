/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:06:00 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 15:14:32 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon*     weapon;
    public:
        HumanB(const std::string& name);
        void    setWeapon(Weapon& weapon);
        void    attack(void);
};

#endif
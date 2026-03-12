/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:59:09 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/03 09:37:48 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
    
    private:
        std::string name;
    public:
		Zombie(void);
		Zombie(std::string name);
		void    announce(void);
		void    setName( std::string name );
		~Zombie(void);
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
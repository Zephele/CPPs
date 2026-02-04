/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:47:27 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 12:57:40 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class   Zombie{
    private:
        std::string name;
    public:
        void    announce(void);
        void    setName( std::string name );
        ~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
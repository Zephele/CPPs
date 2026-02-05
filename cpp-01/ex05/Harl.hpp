/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:10:42 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/05 14:42:04 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl{

    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
    public:
        Harl();
        void    (Harl::*actions[4])();
        void    complain( std::string level ); 
};

#endif
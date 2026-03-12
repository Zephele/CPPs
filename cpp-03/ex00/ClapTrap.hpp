/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:09:47 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/09 09:28:45 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap{
	private:
		std::string	name;
		int	hP;
		int	eP;
		int	aD;
	public:
	// Constructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
	// Destructor
		~ClapTrap();
	// Moviments
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	// Getters
		std::string getName() const;
		int getHp() const;
		int getEp() const;
		int getAd() const;
	// Setters
		void setHp(int hp);
		void setEp(int ep);
		void setAd(int ad);
};


#endif
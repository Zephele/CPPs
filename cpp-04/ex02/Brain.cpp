/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:23:01 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/09 14:22:38 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called!" << std::endl;	
}

Brain::Brain(const Brain& other){
	std::cout << "Brain copy constructor called!" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other){
	if (this != &other){
		std::cout << "Brain copy assignment operator called!" << std::endl;
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor called!" << std::endl;
}	

void Brain::setIdea(int idx, const std::string& idea){
    if (idx >= 0 && idx < 100)
        ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const{
    if (idx >= 0 && idx < 100)
        return ideas[idx];
    return std::string();
}

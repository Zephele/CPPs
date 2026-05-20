/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:19:28 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/29 17:19:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int> copy(mstack);
	std::cout << copy.top() << std::endl;

	const MutantStack<int> constStack(mstack);
	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 04:46:20 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/22 09:34:43 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>
# include <cstdlib>

class PmergeMe {
	private:
		std::vector<int>	_vecNums;
		std::list<int>		_listNums;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void				fillVector(int argc, char* argv[]);
		std::vector<int>	sortVector(std::vector<int> vector);
		void				pairSeparate(std::vector< std::vector<int> >& matriz, std::vector<int> vector);
		void				sortPairs(std::vector< std::vector<int> >& matriz, bool* oddnum);

		std::vector<int> getVecNumns(){
			return _vecNums;
		}
};

#endif
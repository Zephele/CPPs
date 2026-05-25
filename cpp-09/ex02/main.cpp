/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 04:46:27 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/25 16:12:29 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printArray(std::vector<int> v);
void	printArray(std::list<int> l);
int numsChecker(int argc, char* argv[]);
int dupChecker(int argc, char* argv[]);

int	main(int argc, char* argv[]){
	if (argc == 1){
		std::cout << "./PmergeMe 5 4 3 2 1" << std::endl;
		return 1;
	}
	if (numsChecker(argc, argv)) {return 1;}
	if (dupChecker(argc, argv)) {return 1;}
	PmergeMe numArray;

	// --- Vector ---
	clock_t startVec = clock();
	numArray.fillVector(argc, argv);
	std::vector<int> sortedVec = numArray.sortVector(numArray.getVecNumns());
	clock_t endVec = clock();

	// --- List ---
	clock_t startList = clock();
	numArray.fillList(argc, argv);
	std::list<int> sortedlist = numArray.sortList(numArray.getListNums());
	clock_t endList = clock();

	// --- Output ---
	std::cout << "After:\t";
	for (std::vector<int>::iterator it = sortedVec.begin(); it != sortedVec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	double timeVec  = static_cast<double>(endVec  - startVec)  / CLOCKS_PER_SEC * 1000000;
	double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::vector : " << timeVec  << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1
				<< " elements with std::list   : " << timeList << " us" << std::endl;
	
	return 0;
}

//==================================================//
//					EXTRA FUNCTIONS					//
//==================================================//

void	printArray(std::vector<int> v){
	for(unsigned int i = 0; i < v.size(); i++){
		if (i < v.size() - 1)
			std::cout << v[i] << " ";
		else
			std::cout << v[i] << std::endl;
	}
}

void	printArray(std::list<int> l){
	std::list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++){
			std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int numsChecker(int argc, char* argv[]){
	for (int i = 1; i < argc; i++){
		int j = 0;
		if (isdigit(argv[i][j])){
			while (isdigit(argv[i][j])){
				j++;
			}
			if (argv[i][j] == '\0' && atoi(argv[i]) > 0)
				continue ;
			else {
				std::cout << "Error" << std::endl;
				return 1;
			}
		}
		else {
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	return 0;
}

int dupChecker(int argc, char* argv[]){
	std::string num;
	for (int i = 1; i < argc; i++){
		for (int j = i + 1; j < argc; j++){
			if (atoi(argv[i]) == atoi(argv[j])){
				std::cout << "Error" << std::endl;
				return 1;
			}
		}
	}
	return 0;
}

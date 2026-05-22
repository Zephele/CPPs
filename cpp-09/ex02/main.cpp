/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 04:46:27 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/22 09:33:20 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printArray(std::vector<int> v){
	for(unsigned int i = 0; i < v.size(); i++){
		if (i < v.size() - 1)
			std::cout << v[i] << ", ";
		else
			std::cout << v[i] << std::endl;
	}
}

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
	
	numArray.fillVector(argc, argv);
	std::vector<int> sorted = numArray.sortVector(numArray.getVecNumns());
	std::cout << "After:\t";
	printArray(sorted);
	return 0;
}

//==================================================//
//					EXTRA FUNCTIONS					//
//==================================================//

int numsChecker(int argc, char* argv[]){
	for (int i = 1; i < argc; i++){
		int j = 0;
		if (isdigit(argv[i][j])){
			while (isdigit(argv[i][j])){
				j++;
			}
			if (argv[i][j] == '\0')
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

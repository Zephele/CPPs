/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 04:46:24 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/22 09:38:59 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//==========================================//
//				CONSTRUCTORS				//
//==========================================//

PmergeMe::PmergeMe(): _vecNums(std::vector<int>()) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vecNums(other._vecNums){}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other)
		_vecNums = other._vecNums;
	return *this;
}

PmergeMe::~PmergeMe(){}

//==========================================//
//				FUNCTIONS					//
//==========================================//

void	PmergeMe::fillVector(int argc, char* argv[]){
	for (int i = 1; i < argc; i++){
		_vecNums.push_back(atoi(argv[i]));
	}
	std::vector<int>::iterator it;
	std::cout << "Before:\t";
	for (it = _vecNums.begin(); it != _vecNums.end(); it++){
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void	printArrays(std::vector< std::vector<int> >matriz){
	for(unsigned int i = 0; i < matriz.size(); i++){
		for(unsigned int j = 0; j < matriz[i].size(); j++){
			if (j < matriz[i].size() - 1)
				std::cout << matriz[i][j] << ", ";
			else
				std::cout << matriz[i][j] << std::endl;
		}
	}
	std::cout << std::endl;
}

// void	printArray(std::vector<int> v){
// 	for(unsigned int i = 0; i < v.size(); i++){
// 		if (i < v.size() - 1)
// 			std::cout << v[i] << ", ";
// 		else
// 			std::cout << v[i] << std::endl;
// 	}
// }

void	PmergeMe::pairSeparate(std::vector< std::vector<int> >& matriz, std::vector<int> vector){
	std::vector<int>::iterator it;
	int j = 0;
	for (it = vector.begin(); it != vector.end();){
		std::vector<int> tempNums;
		j = 0;
		while (j < 2 && it != vector.end()){
			tempNums.push_back(*it);
			++it;
			++j;
		}
		matriz.push_back(tempNums);
	}
}

void	sortOnlyPair(std::vector<int>& _newVector){
	if (_newVector[0] > _newVector[1]){
		int temp = _newVector[0];
		_newVector[0] = _newVector[1];
		_newVector[1] = temp;
	}
}

void	PmergeMe::sortPairs(std::vector< std::vector<int> >& matriz, bool* oddnum){

	for (unsigned int i = 0; i < matriz.size(); i++){
		if (matriz[i].size() < 2) {
			*oddnum = true;
			continue;
		}
		if (matriz[i][0] > matriz[i][1]){
			int temp = matriz[i][0];
			matriz[i][0] = matriz[i][1];
			matriz[i][1] = temp;
		}
	}
}

std::vector<int>	newVector(std::vector< std::vector<int> >& matriz, bool* oddnum){
	std::vector<int> tempVector;
	if (*oddnum){
		for (long unsigned int i = 0; i < (matriz.size() - 1); i++){
			tempVector.push_back(matriz[i][1]);
		}
	}else {		
		for (long unsigned int i = 0; i < matriz.size(); i++){
			tempVector.push_back(matriz[i][1]);
		}
	}
	return tempVector;
}

std::vector<int>	PmergeMe::sortVector(std::vector<int> vector){
	if (vector.size() <= 1)
		return vector;
	
	std::vector< std::vector<int> > matriz;
	bool oddnum = false;

	//separa em duplas
	pairSeparate(matriz, vector);
	//ordenar as duplas
	sortPairs(matriz, &oddnum);
	//crio um array so com os maiores numeros
	std::vector<int> _newVector = newVector(matriz, &oddnum);

	if (_newVector.size() > 1)
		_newVector = sortVector(_newVector);

	for (unsigned int i = 0; i < matriz.size(); i++){
        if (matriz[i].size() < 2) continue; // pula o ímpar
        
        int menor = matriz[i][0]; // menor do par
        int par   = matriz[i][1]; // par dele (já está em _newVector)

        // busca binária até a posição do par
        std::vector<int>::iterator limite = 
            std::find(_newVector.begin(), _newVector.end(), par);

        std::vector<int>::iterator pos = 
            std::lower_bound(_newVector.begin(), limite, menor);

        _newVector.insert(pos, menor);
    }

	if (oddnum){
        int impar = matriz.back()[0];
        std::vector<int>::iterator pos = 
            std::lower_bound(_newVector.begin(), _newVector.end(), impar);
        _newVector.insert(pos, impar);
    }

	return _newVector;
}
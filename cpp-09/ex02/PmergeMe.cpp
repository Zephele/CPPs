/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 04:46:24 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/25 16:13:56 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//==========================================//
//				CONSTRUCTORS				//
//==========================================//

PmergeMe::PmergeMe(): _vecNums(std::vector<int>()), _listNums(std::list<int>()) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vecNums(other._vecNums), _listNums(other._listNums) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other){
		_listNums = other._listNums;
		_vecNums = other._vecNums;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

//==========================================//
//				FUNCTIONS					//
//==========================================//

//------//
//-LIST-//
//------//

void	PmergeMe::fillList(int argc, char* argv[]){
	for (int i = 1; i < argc; i++){
		_listNums.push_back(atoi(argv[i]));
	}
	std::list<int>::iterator it;
	// std::cout << "Before:\t";
	// for (it = _listNums.begin(); it != _listNums.end(); it++)
	// 	std::cout << *it << ' ';
	// std::cout << std::endl;
}

static void pairSeparateList(std::list< std::list<int> >& matriz, std::list<int> list){
	std::list<int>::iterator it;
	int i = 0;

	for (it = list.begin(); it != list.end();){
		std::list<int> tempNums;
		i = 0;
		while (i < 2 && it != list.end()){
			tempNums.push_back(*it);
			++it;
			++i;
		}
		matriz.push_back(tempNums);
	}
}

static void sortPairsList(std::list< std::list<int> >& matriz, bool* oddnum){
	std::list< std::list<int> >::iterator itM;
	std::list<int>::iterator it;

	for (itM = matriz.begin(); itM != matriz.end(); itM++){
		if (itM->size() < 2){
			*oddnum = true;
			continue;
		}
		it = itM->begin();
		int first = *it;
		it++;
		int second = *it;
		it--;
		if (first > second){
			*it = second;
			it++;
			*it = first;
		}
	}
}

std::list<int> newList(std::list< std::list<int> >& matriz, bool* oddnum){
	std::list<int> tempList;
	std::list< std::list<int> >::iterator itM;
	std::list<int>::iterator it;

	if (*oddnum) {
		std::list< std::list<int> >::iterator last = matriz.end();
		last--;
		for (itM = matriz.begin(); itM != last; itM++){
			tempList.push_back(itM->back());
		}
	} else {
		for (itM = matriz.begin(); itM != matriz.end(); itM++){
			tempList.push_back(itM->back());
		}
	}
	return tempList;
}

std::list<int> PmergeMe::sortList(std::list<int> list){
	std::list< std::list<int> >::iterator itM;
	std::list<int>::iterator it;
	if (list.size() <= 1)
		return list;

	std::list< std::list<int> > matriz;
	bool oddnum = false;

	pairSeparateList(matriz, list);
	sortPairsList(matriz, &oddnum);
	std::list<int> _newList = newList(matriz, &oddnum);

	if (_newList.size() > 1)
		_newList = sortList(_newList);

	for (itM = matriz.begin(); itM != matriz.end(); itM++){
		if (itM->size() < 2) continue;

		it = itM->begin();
		int menor = *it;
		++it;
		int par = *it;

		std::list<int>::iterator limit =
			std::find(_newList.begin(), _newList.end(), par);

		std::list<int>::iterator pos = _newList.begin();
		while (pos != limit && *pos < menor)
			++pos;

		_newList.insert(pos, menor);
	}

	if (oddnum){
		int impar = matriz.back().front();
		std::list<int>::iterator pos = _newList.begin();
		while (pos != _newList.end() && *pos < impar)
			++pos;
		_newList.insert(pos, impar);
	}

	return _newList;
}

//--------//
//-VECTOR-//
//--------//

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
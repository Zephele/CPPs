/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:21:36 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/28 17:59:44 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0){}

Span::Span(unsigned int n) : _N(n){
	_vec.reserve(_N);
}

Span::Span(const Span& other){
	*this = other;
}

Span& Span::operator=(const Span& other){
	if (this != &other){
		this->_N = other._N;
		_vec = other._vec;
	}
	return (*this);
}

Span::~Span(){}

class MaximumCapacityReached : public std::exception {
	public :
		virtual const char* what() const throw() {return "Maximum capacity reached.";}
};

void	Span::addNumber(unsigned int num){
	if (_vec.size() != _N){
		_vec.push_back(num);
		return ;
	}
	else
		throw MaximumCapacityReached();
}

void Span::addNumbers(const int* arr, std::size_t len) {
	if (_vec.size() + len > _N) throw MaximumCapacityReached();
	_vec.insert(_vec.end(), arr, arr + len);
}

class NotEnoughNumbers : public std::exception {
	public :
		virtual const char* what() const throw() {return "Not enough numbers.";}
};

unsigned int	Span::shortestSpan(){
	if (_vec.size() == 0 || _vec.size() == 1)
		throw NotEnoughNumbers();
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());

	unsigned int shortest = static_cast<unsigned int>(tmp[1] - tmp[0]);
	for (std::size_t i = 1; i < tmp.size() - 1; ++i) {
		unsigned int diff = static_cast<unsigned int>(tmp[i + 1] - tmp[i]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int	Span::longestSpan(){
	if (_vec.size() == 0 || _vec.size() == 1)
		throw NotEnoughNumbers();

	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());

	int minVal = *std::min_element(_vec.begin(), _vec.end());
	int maxVal = *std::max_element(_vec.begin(), _vec.end());

	return static_cast<unsigned int>(maxVal - minVal);
}

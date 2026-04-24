/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:40:53 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/23 22:21:56 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(NULL), _n(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _n(n){}

template <typename T>
Array<T>::Array(const Array<T>& other) : _arr(NULL), _n(other._n){
	_arr = new T[_n];
	for(unsigned int i = 0; i < _n; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other){
	if (this != &other){
		delete[] _arr;
		_n = other._n;
		_arr = new T[_n];
		for(unsigned int i = 0; i < _n; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] _arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _n)
		throw std::out_of_range("Array index out of range");
	return _arr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= _n)
	throw std::out_of_range("Array index out of range");
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size(void) const{
	return (_n);
}

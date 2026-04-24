/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:51:03 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/09 15:02:09 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename X>
void print(const X& i) {
	std::cout << i << " ";
}

template <typename X>
void setZero(X& i) {
	i = 0;
}

int main()
{
	std::cout << "=== Teste com int ===" << std::endl;
	int iarr[] = {1, 2, 3, 4};
	::iter(iarr, 4, print<int>);
	std::cout << std::endl;
	std::cout << "Zerando..." << std::endl;
	::iter(iarr, 4, setZero<int>);
	::iter(iarr, 4, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== Teste com char ===" << std::endl;
	char carr[] = {'A', 'B', 'C'};
	::iter(carr, 3, print<char>);
	std::cout << std::endl;
	std::cout << "Zerando..." << std::endl;
	::iter(carr, 4, setZero<char>);
	::iter(carr, 4, print<char>);
	std::cout << std::endl;

	std::cout << "\n=== Teste com double ===" << std::endl;
	double darr[] = {1.1, 2.2, 3.3};
	::iter(darr, 3, print<double>);
	std::cout << std::endl;
	std::cout << "Zerando..." << std::endl;
	::iter(darr, 4, setZero<double>);
	::iter(darr, 4, print<double>);
	std::cout << std::endl;

	std::cout << "\n=== Teste com const ===" << std::endl;
	const int arr2[] = {5, 6, 7, 8};
	::iter(arr2, 4, print<int>); //não deve funcionar se a func for setZero
	std::cout << std::endl;

	return (0);
}
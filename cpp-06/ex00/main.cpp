/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:18:51 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/06 17:45:56 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]){
	if (argc > 2 || argc == 1) {
		std::cout << "[INVALID INPUT] Expected: ./converter <string>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
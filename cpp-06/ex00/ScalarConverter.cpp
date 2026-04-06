/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:18:41 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/02 18:25:14 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <climits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter& other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

//==========================

bool ScalarConverter::isChar(std::string toConvert){
	if (toConvert.size() == 1 && !std::isdigit(toConvert[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(std::string toConvert){
	char		*end;
	long int	value;

	errno = 0;
	value = std::strtol(toConvert.c_str(), &end, 10);
	if (errno == ERANGE || *end != '\0' || end == toConvert.c_str())
		return false;
	if (value < INT_MIN || value > INT_MAX)
		return false;
	return true;
}

bool ScalarConverter::isFloat(std::string toConvert){
	char		*end;
	long int	value;

	errno = 0;
	value = std::strtof(toConvert.c_str(), &end);
	if (errno == ERANGE || *end != '\0' || end == toConvert.c_str())
		return false;
	if (*end == 'f' && *(end + 1) == '\0')
		return false;
	return true;
}

bool ScalarConverter::isDouble(std::string toConvert){
	char *end;
	errno = 0;
	
	std::strtod(toConvert.c_str(), &end);
	if (errno == ERANGE || *end != '\0' || end == toConvert.c_str())
		return (false);
	return (true);
}


void ScalarConverter::convertChar(std::string toConvert){
	
}

void ScalarConverter::convertInt(std::string toConvert){
	
}

void ScalarConverter::convertFloat(std::string toConvert){
	
}

void ScalarConverter::convertDouble(std::string toConvert){
	
}


//==========================

void ScalarConverter::convert(std::string toConvert){
	std::cout << std::fixed << std::setprecision(1);

	int		strInt = atoi(toConvert.c_str()); //String to int.
	float	strFloat = (float)atof(toConvert.c_str()); //String to float.
	double	strDouble = atof(toConvert.c_str()); //String to double.

	std::cout << "int: " << strInt << std::endl;
	std::cout << "float: " << (float)strFloat << "f" << std::endl;
	std::cout << "double: " << strDouble << std::endl;
}

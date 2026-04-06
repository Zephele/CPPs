/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:18:37 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/02 16:13:30 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter& other);
		~ScalarConverter();

		static bool isChar(std::string toConvert);
		static bool isInt(std::string toConvert);
		static bool isFloat(std::string toConvert);
		static bool isDouble(std::string toConvert);

		static void convertChar(std::string toConvert);
		static void convertInt(std::string toConvert);
		static void convertFloat(std::string toConvert);
		static void convertDouble(std::string toConvert);

		static void convert(std::string toConvert);
};

#endif
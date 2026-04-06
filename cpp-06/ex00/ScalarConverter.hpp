/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:18:37 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/06 18:16:41 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <climits>
# include <cfloat>
# include <cerrno>

class ScalarConverter{
	public:
		static bool isPseudo(const std::string& toConvert);
		static bool isChar(const std::string& toConvert);
		static bool isInt(const std::string& toConvert);
		static bool isFloat(const std::string& toConvert);
		static bool isDouble(const std::string& toConvert);

		static void convertPseudo(const std::string& toConvert);
		static void convertChar(const std::string& toConvert);
		static void convertInt(const std::string& toConvert);
		static void convertFloat(const std::string& toConvert);
		static void convertDouble(const std::string& toConvert);

		static void convert(const std::string& toConvert);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter& other);
		ScalarConverter& operator=(ScalarConverter& other);
		~ScalarConverter();
};

#endif
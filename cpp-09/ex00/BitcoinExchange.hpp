/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:01:33 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/20 14:48:07 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <iomanip>
# include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

//==============================================================================================================//
//											ERRORS CLASSES														//
//==============================================================================================================//
		class CsvFileNotFounded : public std::exception {
			public :
				virtual const char* what() const throw() {return "could not open the csv file.";}
			};

		class BadInputException : public std::exception {
			private:
				std::string _msg;
			public :
				BadInputException(const std::string &line) {
					std::ostringstream oss;
					oss << "bad input => " << line;
					_msg = oss.str();
				}
				virtual ~BadInputException() throw() {}
				virtual const char* what() const throw() {return _msg.c_str();}
			};

		class NotPositiveNumberException : public std::exception {
			public :
				virtual const char* what() const throw() {return "not a positive number.";}
			};

		class BitcoinDontExistException : public std::exception {
			public :
				virtual const char* what() const throw() {return "Bitcoin dont exist in this data.";}
			};

		class BadDateException : public std::exception {
			private:
				std::string _msg;
			public :
				BadDateException(const std::string &line) {
					std::ostringstream oss;
					oss << "bad date => " << line;
					_msg = oss.str();
				}
				virtual ~BadDateException() throw() {}
				virtual const char* what() const throw() {return _msg.c_str();}
			};

		class LargeNumberException : public std::exception {
			public :
				virtual const char* what() const throw() {return "too large a number.";}
			};

//==============================================================================================================//
//												Functions														//
//==============================================================================================================//

		std::map<std::string, double> fileConvert();
		void printMap();

		std::string mapKeyValid(std::string line);
		int validDateValue(std::string line);
		int validData(std::string line);
		int validValue(std::string line);
		void validFileLine(std::string line);
};

#endif
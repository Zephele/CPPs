/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:00:35 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/20 15:16:49 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::map<std::string, double> BitcoinExchange::fileConvert(){
	std::ifstream fileIn;
	std::string line;
	std::map<std::string, double> data;

	fileIn.open("data.csv");
	if (fileIn.is_open()){
		while (std::getline(fileIn, line)){
			data[line.substr(0, 10)] = atof((line.substr(11, (line.size() - 11))).c_str());
		}
	} else 
		throw CsvFileNotFounded();
	return data;
}

// void BitcoinExchange::printMap(){
// 	typedef std::map<std::string, double> MapType;
// 	for (MapType::const_iterator it = _data.begin(); it != _data.end(); ++it){
// 			std::cout << it->first << " => " << it->second << std::endl;
// 		}
// }

//==========================================================================//
//							CONSTRUCTORS									//
//==========================================================================//

BitcoinExchange::BitcoinExchange(): _data(fileConvert()){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other)
		this->_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

//==========================================================================//
//								VALIDACAO									//
//==========================================================================//

int BitcoinExchange::validDateValue(std::string line){
	if (line.size() < 14){
		throw BadInputException(line);
	}
	for (std::size_t i = 0; i < line.size(); i++){
		if ((i <= 3) || (i >= 5 && i <= 6) || (i >= 8 && i <= 9)){
			if (!(isdigit(static_cast<unsigned char>(line[i]))))
				throw BadInputException(line);
		}
		else if (i == 4 || i == 7 || i == 11){
			if (i == 4 || i == 7) {
				if ((line[i]) != '-')
					throw BadInputException(line);
			} else {
				if ((line[i]) != '|')
					throw BadInputException(line);
			}
		}
		else {
			if ((line[i]) == '-'){
				throw NotPositiveNumberException();
			if ((!(isdigit(static_cast<unsigned char>(line[i])))) 
				&& line[i] != '.')
					throw BadInputException(line);
			}
		}
	}
	return 0;
}

static bool isLeap(int year){
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

int BitcoinExchange::validData(std::string line){
	int year, month, day, maxDay;
	bool leap;

	year = atoi((line.substr(0, 4)).c_str());
	month = atoi((line.substr(5, 2)).c_str());
	day = atoi((line.substr(8, 2)).c_str());
	leap = isLeap(year);

	if (year < 2009 || (year == 2009 && (month < 1 || (month == 1 && day < 2))))
		throw BitcoinDontExistException();
	if (month == 2)
		maxDay = leap ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;
	else
		maxDay = 31;

	if (month < 1 || month > 12 || day < 1 || day > maxDay)
		throw BadDateException(line);
	return 0;
}

static bool intOrDouble(std::string line){
	std::string lineTemp = line.substr(13, (line.size() - 13));
	for (size_t i = 0; i < lineTemp.size(); i++){
		if (lineTemp[i] == '.')
			return false;
	}
	return true;
}

int BitcoinExchange::validValue(std::string line){
	bool intVal = intOrDouble(line);
	if (intVal == true){
		int intValue = atoi((line.substr(13, (line.size() - 13)).c_str()));
		if (intValue >= 0 && intValue <= 1000)
			return 0;
		else
			throw LargeNumberException();
		// std::cout << intValue << std::endl;
	}
	else{
		double doubleValue = atof((line.substr(13, (line.size() - 13)).c_str()));
		if (doubleValue >= 0 && doubleValue <= 1000)
			return 0;
		else 
			throw LargeNumberException();
		// std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	}
	return 0;
}

std::string BitcoinExchange::mapKeyValid(std::string date){
	int year, month, day;
	std::string	dateValid = date;

	year = atoi((date.substr(0, 4)).c_str());
	month = atoi((date.substr(5, 2)).c_str());
	day = atoi((date.substr(8, 2)).c_str());

		while (this->_data.find(dateValid) == this->_data.end()){
			if (year < 2009 || (year == 2009 && month == 1 && day < 2))
				return "Error";

			if (day > 1) {
				day--;
			} else {
				if (month > 1)
					month--;
				else {
					month = 12;
					year--;
				}
				int maxDay;
				if (month == 2)
					maxDay = isLeap(year) ? 29 : 28;
				else if (month == 4 || month == 6 || month == 9 || month == 11)
					maxDay = 30;
				else
					maxDay = 31;
				day = maxDay;
			}
			std::ostringstream oss;
			oss << std::setw(4) << std::setfill('0') << year << '-' << std::setw(2) << month << '-' << std::setw(2) << day;
			dateValid = oss.str();
		}
	
	return dateValid;
}

void BitcoinExchange::validFileLine(std::string line){
	if (line.find("date | value") == 0)
		return ;
	if (validDateValue(line))
		return ;
	if (validData(line))
		return ;
	if (validValue(line))
		return ;
	else {
		float value = 0;
		std::string date = line.substr(0, 10);
		std::string lineVal = line.substr(13, (line.size() - 13));
		std::map<std::string, double>::const_iterator it = this->_data.find(date);
		if (it == this->_data.end()){
			std::string key = mapKeyValid(date);
			if (key == "Error")
				throw BitcoinDontExistException();
		} else {
			value = it->second;
		}

		std::string _print = date + " => " + lineVal + " = ";
		
		float finalValue = (value * atof((line.substr(13, (line.size() - 13)).c_str())));
		std::cout << _print << finalValue << std::endl;
		return ;
	}
}
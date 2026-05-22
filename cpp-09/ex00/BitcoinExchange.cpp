/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:00:35 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/20 16:31:37 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::map<std::string, double> BitcoinExchange::fileConvert(){
	std::ifstream fileIn;
	std::string line;
	std::map<std::string, double> data;

	fileIn.open("data.csv");
	if (fileIn.is_open()){
		std::getline(fileIn, line);
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
		else if (i == 10 || i == 12){
			if (line[i] != ' ')
				throw BadInputException(line);
		}
		else {
			break;
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

static bool validNumberToken(const std::string &token){
	if (token.empty())
		return false;
	if (token[0] == '-')
		return true;
	bool dotSeen = false;
	bool digitSeen = false;
	for (std::size_t i = 0; i < token.size(); ++i){
		if (token[i] == '.'){
			if (dotSeen)
				return false;
			dotSeen = true;
		} else if (isdigit(static_cast<unsigned char>(token[i]))){
			digitSeen = true;
		} else {
			return false;
		}
	}
	return digitSeen;
}

int BitcoinExchange::validValue(std::string line){
	std::string valueToken = line.substr(13, (line.size() - 13));
	if (valueToken.size() > 0 && valueToken[0] == '-')
		throw NotPositiveNumberException();
	if (!validNumberToken(valueToken))
		throw BadInputException(line);
	double value = atof(valueToken.c_str());
	if (value >= 0 && value <= 1000)
		return 0;
	throw LargeNumberException();
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
			if (key == "Error"){
				throw BitcoinDontExistException();
			} else {
				value = this->_data[key];
			}
		} else {
			value = it->second;
		}
		std::string _print = date + " => " + lineVal + " = ";
		
		float finalValue = (value * atof((line.substr(13, (line.size() - 13)).c_str())));
		std::cout << _print << finalValue << std::endl;
		return ;
	}
}
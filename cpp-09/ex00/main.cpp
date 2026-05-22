/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:00:38 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/20 16:22:47 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]){
	std::string filename, line;

	if (argc != 2){
		std::cout << "Example:{./btc filename}" << std::endl;
		return (1);
	}

	filename = argv[1];
	bool	header = false;
	BitcoinExchange btc;
	std::ifstream fileIn;
	fileIn.open(filename.c_str());
	if (fileIn.is_open()){
		while (std::getline(fileIn, line)){
			if (line.find("date | value") == 0 && header == false)
				header = true;
			else {				
				try{
					btc.validFileLine(line);
				} catch (const std::exception& e) {
					std::cout << "Error: " << e.what() << std::endl;
					continue;
				}
			}
		}
	} else {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	return 0;
}
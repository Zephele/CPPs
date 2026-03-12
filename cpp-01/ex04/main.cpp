/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:05:29 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/02 16:41:15 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceLine(std::string line, std::string s1, std::string s2){
    if (s1.empty())
        return (line);

    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
    }
    return (line);
}

int main(int argc, char *argv[]){
    std::string filename, s1, s2, newLine;

    if (argc != 4){
        std::cout << "Example:{./sed filename s1 s2}" << std::endl;
        return (1);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];

    std::ifstream   fileIn;
    std::ofstream   fileOut;
    std::string     line;
    fileIn.open(filename.c_str());
    if(fileIn.is_open()){
        fileOut.open((filename + ".replace").c_str());
        if (!fileOut.is_open()){
            std::cout << "The output file cannot be opened" << std::endl;
            return (1);
        }
        while (std::getline(fileIn, line)){
            newLine = replaceLine(line, s1, s2);
            fileOut << newLine << std::endl;
        }
        fileIn.close();
        fileOut.close();
    }else{
        std::cout << "The file cannot be opened" << std::endl;
        return (1);
    }
    return (0);
}

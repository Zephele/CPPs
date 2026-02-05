/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:05:29 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/05 12:59:34 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

//ofstream, ifstream, fstream
//out,      in,       both

//para abrir um arquivo [filename.open()]

//se eu achar s1 na linha eu devo substituir por s2

//eu preciso ir rescrevendo, 
//coloco o valor de i como o do final apos a copia

std::string replaceLine(std::string line, std::string s1, std::string s2){
    std::string newLine;
        if (s1.empty())
            return line;

        size_t i = 0;
        while (i < line.size()){
            size_t j = 0;
            while (i + j < line.size() && j < s1.size() && line[i + j] == s1[j])
                j++;
            if (j == s1.size()){
                newLine += s2;
                i += s1.size();
            } else {
                newLine += line[i];
                i++;
            }
        }
        return newLine;
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

    //Abrindo o arquivo e copiando os dados
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
    }
    return (0);
}

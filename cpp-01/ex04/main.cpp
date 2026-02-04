/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:05:29 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/04 17:32:11 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

//ofstream, ifstream, fstream
//out,      in,       both

//para abrir um arquivo [filename.open()]

int main(int argc, char *argv[]){
    std::string filename, s1, s2;

    if (argc != 4){
        std::cout << "Example:{./sed filename s1 s2}" << std::endl;
        return (1);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    std::ofstream   FileOut;
    FileOut.open((filename + ".replace").c_str());
    return (0);
}
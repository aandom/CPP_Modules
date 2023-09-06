/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:17:12 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 21:17:12 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string fileName) : infile(fileName) {
    this->outfile = this->infile + ".replace";
}

Sed::~Sed() {
}

void    Sed::replacestr(std::string to_find, std::string to_replace)
{
    std::ifstream    myinfile(this->infile.c_str());
    if (myinfile.is_open()) {
        std::string content;
        if (std::getline(myinfile, content, '\0')) {
            std::ofstream   myoutfile(this->outfile.c_str());
            size_t          pos = content.find(to_find);
            while(pos != std::string::npos) {
                content.erase(pos, to_find.length());
                content.insert(pos, to_replace);
                pos = content.find(to_find);
            }
            myoutfile << content;
            myoutfile.close();
        } 
        else {
            std::cerr << "Input File is empty" << std::endl;
        }
        myinfile.close();
    }
    else {
        std::cerr << "Error occurred while opening the input File" << std::endl;
        exit(1);
    }
}

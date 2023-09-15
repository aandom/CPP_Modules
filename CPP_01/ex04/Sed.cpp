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

int Sed::openfiles() {
    this->ifs.open(this->infile.c_str(), std::ifstream::in);
    if (!this->ifs.good()) {
        std::cerr << "Eror: " << this->infile << ": " << std::strerror(errno) << std::endl;
        return (-1);
    }
    this->ofs.open(this->outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!this->ofs.good()) {
        std::cerr << "Eror: " << this->outfile << ": " << std::strerror(errno) << std::endl;
        return (-1);
    }
    return (0);
}

int Sed::replacestr(std::string to_find, std::string to_replace) {

        std::string content;

        if (this->openfiles() == -1 ) {
            return (-1);
        }
        std::getline(this->ifs, content, '\0');
        if (this->ifs.fail())
            return (-1);
        size_t  pos = content.find(to_find);
        while(pos != std::string::npos) {
            content.erase(pos, to_find.length());
            content.insert(pos, to_replace);
            pos = content.find(to_find);
        }
        this->ofs << content;
        this->ofs.close();
        this->ofs.close();
        return (0);
} 
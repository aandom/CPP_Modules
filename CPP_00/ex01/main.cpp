/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:44:16 by aandom            #+#    #+#             */
/*   Updated: 2023/08/21 12:44:16 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>


std::string get_option(PhoneBook *phonebook){
    std::string input;
    std::cout << ">>>> " << std::flush;
    if (!std::getline(std::cin, input) || std::cin.eof()) {
        std::cout << "EXIT" << std::endl;
        return ("EXIT");
    }
    input = phonebook->trim_space(input);
    return (input);
}

int main(void) {
    PhoneBook   myphonebook;
    std::string input;
    myphonebook.start();
    while (true)
    {
        input = get_option(&myphonebook);
        for (std::string::iterator str = input.begin(); str != input.end(); str++)
			*str = std::toupper(*str);
        if (input == "EXIT") {
            break;
        } else if (input == "ADD") {
            if (!myphonebook.add())
                break;
        } else if (input == "SEARCH") {
            if(!myphonebook.searchCon()) {
                break;
            } 
        } 
    }
    return (0);
}
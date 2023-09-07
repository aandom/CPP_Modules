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
            if(myphonebook.searchCon()) {
                myphonebook.display_contacts();
                myphonebook.search();
            } 
        } else {
                std::cout << "[---USAGE---]" << std::endl;
                std::cout << "ADD\t: To add a contact." << std::endl;
                std::cout << "SEARCH\t: To search for a contact." << std::endl;
                std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
                std::cout << "............................................." << std::endl;
                std::cout << std::endl;
        }
        // std::cout << ">>>> " << std::flush;
    }
    return (0);
}






// int main(void) {
//     PhoneBook   myphonebook;
//     std::string input = "";
//     myphonebook.start();
//     while (input.compare("EXIT"))
//     {
//         if (input.compare("ADD") == 0)
//         {
//             std::cout << "adding contact" << input << std::endl;
//             myphonebook.add();
//         }
//         else if (input.compare("SEARCH") == 0) {

//             myphonebook.display_contacts();
//             myphonebook.search();
//         }
//         std::cout << ">>>> " << std::flush;
//         std::cin >> input;
//     }
//     return (0);
// }

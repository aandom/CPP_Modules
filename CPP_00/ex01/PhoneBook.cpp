/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:44:19 by aandom            #+#    #+#             */
/*   Updated: 2023/08/21 12:44:19 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::trim_space(std::string str) {
    std::string is_space = " \t\n\r\v\f";
    size_t start;
    size_t end;

    start = str.find_first_not_of(is_space);
    end = str.find_last_not_of(is_space);
    if (start == end)
        return (str);
    return (str.substr(start, end - start + 1));
}


void    PhoneBook::start(void) const {
    std::cout << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "| ###########-MY PHONE BOOK-###########   |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "............................................." << std::endl;
    std::cout << "[---USAGE---]" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "............................................." << std::endl;
    std::cout << std::endl;
}



bool   PhoneBook::add(void) {
    static int i;
    if (!this->mycontacts[i % 8].start_input())
        return (false);
    this->mycontacts[i % 8].set_index(i % 8);
    display_contacts();
    i++;
    return (true);
}

void    PhoneBook::display_contacts(void) const {
    std::cout << "[----------------- MY PHONEBOOK CONTACTS -----------------]" << std::endl;
    for (size_t i = 0; i < 8; i++)
    {
        this->mycontacts[i].view(i);
    }
    std::cout << std::endl;
}

int    PhoneBook::get_input() const {
    int index = -1;
    int isvalid = 0;
    while (!isvalid) {
        std::cout << "ENTER CONTACT INDEX: " << std::flush;
        std::cin >> index;
        if ((std::cin.good() && index >= 0 && index < 8) || std::cin.eof()) {
            isvalid = 1;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ERROR INVALID INDEX: please enter again..." << std::endl;
        }
    }
    if (std::cin.eof())
        return (7);
    return (index);
}

void    PhoneBook::search(void) const {
    int i = this->get_input();
    this->mycontacts[i].display(i);
}
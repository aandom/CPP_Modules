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

PhoneBook::PhoneBook() : is_empty(0)
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


bool PhoneBook::allDigits(std::string str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isdigit(*it)) {
			return (false);
		}
	}
	return (true); 
}


bool   PhoneBook::add(void) {
    static int i;
    if (!this->mycontacts[i % 8].start_input())
        return (false);
    this->mycontacts[i % 8].set_index(i % 8);
    is_empty = 1;
    i++;
    return (true);
}

void    PhoneBook::display_contacts(void) const {
    for (size_t i = 0; i < 8; i++)
    {
        this->mycontacts[i].view(i);
    }
    std::cout << std::endl;
}

int	PhoneBook::printContact(std::string const input) {

	int			index;
    std::string scopy = input;

	if (this->allDigits(input)) {
        std::istringstream iss(scopy);
        iss >> index;
		if (index >= 0 && index <= 7) {
			if (this->mycontacts[index].display(index))
				return (0);
			else {
				std::cout << "No record at index [" << index << "]" << std::endl;
				return (0);
			}
		}
        else {
	        std::cout << "ERROR Invalid Index: please enter again..." << std::endl;
            return (1);
        }
	}
     std::cout << "ERROR Index must be an Int value..." << std::endl;
	return (1);
    }


std::string PhoneBook::getIndex(std::string str) {
	std::string	input;

	std::cout << str ;
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		std::cout << std::endl;
		return(std::string());
	}
	// input = trim_sp(input);
    if(input.empty()) {
        return (" ");
    }
	return (input);
}

int    PhoneBook::searchCon(void) {
    std::string input;
    int         status;

    status = 1;
    std::cout << "[----------------- MY PHONEBOOK CONTACTS -----------------]" << std::endl << std::endl;
    if (is_empty == 0) {
        std::cout << "Empty Phonebook" << std::endl;
        return (1);
    }
    display_contacts();
    while (status)
    {
        input = getIndex("ENTER CONTACT INDEX: ");
        if(input.empty()){
            return(0);
        }
        status  = printContact(input);
    }
    return (1);
}
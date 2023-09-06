/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:44:11 by aandom            #+#    #+#             */
/*   Updated: 2023/08/21 12:44:11 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Contact::Contact()
// {
// }

Contact::Contact(void) : isvalid(false) {
	return ;
}

Contact::~Contact()
{
}

std::string Contact::trim_sp(std::string str) {
    std::string is_space = " \t\n\r\v\f";
    size_t start;
    size_t end;

    start = str.find_first_not_of(is_space);
    end = str.find_last_not_of(is_space);
    if (start == end)
        return (str);
    return (str.substr(start, end - start + 1));
}



std::string Contact::read_input(std::string str) {
	std::string	input;

	std::cout << str ;
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		isvalid = true;
		std::cout << std::endl;
		return(std::string());
	}
	input = trim_sp(input);
	return (input);
}




// std::string Contact::read_input(std::string str) const {
//     std::string user_input = "";
//     int isvalid = 0;

//     while(!isvalid) {
//         std::cout << str << std::flush;
//         std::getline (std::cin, user_input);
//         if (std::cin.good() && !user_input.empty()) {
//             isvalid = 1;
//         } else if (std::cin.eof()) {
//             std::cout << "returning NULL" << std::endl;
//             return ("");
//         } 
//         else {
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "ERROR INVALID INPUT : please put valid input..." << std::endl;
//         }

//     }
//     return (user_input);
// }

bool	Contact::validate_input(std::string str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isalpha(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);   
}

bool	Contact::check_input(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!validate_input(str)) {
		std::cout << "Error: Names can only contain letters, spaces and hyphens." << std::endl;
		return (false);
	}
	return (true);
}

bool	Contact::validate_phone(std::string str) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (!std::isdigit(*it) && *it != ' ' && *it != '-') {
			return (false);
		}
	}
	return (true);
}

bool	Contact::check_phone(std::string str) {
	if (str.empty()) {
		return (false);
	}
	else if (!validate_phone(str)) {
		std::cout << "Error: Phone numbers can only contain digits, spaces and hyphens." << std::endl;
		return (false);
	}
	return (true);
}


bool    Contact::start_input(void) {
    std::string input;

    while (!isvalid)
    {
        input = this->read_input("Enter First Name: ");
        if (isvalid)
            break;
        else if (check_input(input)) {
            input[0] = std::toupper(input[0]);
            this->firstName = input;
            break;
        }
    }

    while (!isvalid)
    {
        input = this->read_input("Enter Last Name: ");
        if (isvalid)
            break;
        else if (check_input(input)) {
            input[0] = std::toupper(input[0]);
            this->lastName = input;
            break;
        }
    }

    while (!isvalid)
    {
        input = this->read_input("Enter Nick Name: ");
        if (this->isvalid)
            break;
        else if (check_input(input)) {
            input[0] = std::toupper(input[0]);
            this->nickName = input;
            break;
        }
    }

    while (!isvalid)
    {
        input = this->read_input("Enter Phone Number: ");
        if (this->isvalid)
            break;
        else if (check_phone(input)) {
            this->phoneNumber = input;
            break;
        }
    }

    while (!isvalid)
    {
        input = this->read_input("Enter Dark Secret: ");
        if (isvalid)
            break;
        else if (check_input(input)) {
            input[0] = std::toupper(input[0]);
            this->darkSecret = input;
            break;
        }
    }
    if (isvalid) {
		isvalid = false;
		return (false);
	}
	std::cout << "Contact successfully saved." << std::endl;
	return (true);
}

std::string Contact::updated_str(std::string    str) const {
    if (str.length() > 10)
        return(str.substr(0, 9) + ".");
    return (str);
}


void    Contact::set_index(int i) {
    this->index = i;
}

void    Contact::view (int  index) const {
    if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->updated_str(this->firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->updated_str(this->lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->updated_str(this->nickName) << std::flush;
    std::cout << "|" << std::endl;

}

void    Contact::display (int  index) const {
    if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
        return ;
    std::cout << std::endl;
    std::cout << "[--------- Contact #" << index << "---------]" << std::endl;
    std::cout << "First Name:\t" << this->firstName << std::endl;
    std::cout << "Last Name:\t" << this->lastName << std::endl;
    std::cout << "Nickname:\t" << this->nickName << std::endl;
    std::cout << "Phone number :\t" << this->phoneNumber << std::endl;
    std::cout << "Dark Secret:\t" << this->darkSecret << std::endl;
    std::cout << std::endl;

}
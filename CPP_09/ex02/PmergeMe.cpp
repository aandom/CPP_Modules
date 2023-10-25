/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:10:20 by aandom            #+#    #+#             */
/*   Updated: 2023/10/23 09:10:20 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

static bool    checkInput(std::string const & str) {

    if (str.empty() || str.length() == 0)
        return (false);
    for (std::string::const_iterator it = str.begin(); it != str.end() ; it++) {
        if (it == str.begin() &&  (*str.begin() == '-' || *str.begin() == '+'))
            continue;
        else if (!std::isdigit(*it))
            return (false);
    }
    return (true);
}

int  checkInt(std::string const & input) {
    char *endptr;
    if (!checkInput(input))
        return (-1);
    long nbr = std::strtol(input.c_str(), &endptr, 10);

    if (endptr == input.c_str() || *endptr != '\0')
        return (-1);
    if (nbr > std::numeric_limits<int>::max() || nbr <= 0) {
        return (-1);
    }
    int intform = static_cast<int>(nbr);
    return (intform);
}
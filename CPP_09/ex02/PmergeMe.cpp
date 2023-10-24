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

int  checkInt(std::string const & input) {
    char *endptr;
    long nbr = std::strtol(input.c_str(), &endptr, 10);

    if (endptr == input.c_str() || *endptr != '\0')
        return (false);
    if (nbr > std::numeric_limits<int>::max() || nbr < 0) {
        return (-1);
    }
    int intform = static_cast<int>(nbr);
    return (intform);
}
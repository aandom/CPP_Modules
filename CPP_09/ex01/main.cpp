/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:12:08 by aandom            #+#    #+#             */
/*   Updated: 2023/10/23 09:12:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"


int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Error: Invalid Number of Argument" << std::endl;
        return (1);
    }

    try {
        int res = RPN::computeRPN(av[1]);
        std::cout << "Result: " << res << '\n';
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:31:07 by aandom            #+#    #+#             */
/*   Updated: 2023/10/19 10:31:07 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <fstream>
# include <strings.h>
# include <string.h>
# include <time.h>  
# include <limits>
# include <ctime>
# include <exception>

class BitcoinExchange
{
    public:
        BitcoinExchange(std::string infile);
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange();

        BitcoinExchange & operator=(BitcoinExchange const & src);
        
    private:
        BitcoinExchange();
        std::string              _infile;
        std::map<time_t, double> _data;

        void    parseInput();
        void    insertToMap(time_t date, double value);
        void    computeExhange();
        time_t  findNearestDate(time_t date);

        /* data */
};

std::ostream &	operator<<(std::ostream &os, std::map<long, double> &obj);



# endif
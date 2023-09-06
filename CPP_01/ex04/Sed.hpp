/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:17:18 by aandom            #+#    #+#             */
/*   Updated: 2023/08/29 21:17:18 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

class Sed
{
    private:
        std::string infile;
        std::string outfile;
        
    public:
        Sed(std::string fileName);
        ~Sed();
        void    replacestr(std::string to_find, std::string to_replace);
};

# endif
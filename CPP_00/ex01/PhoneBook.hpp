/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:44:21 by aandom            #+#    #+#             */
/*   Updated: 2023/08/21 12:44:21 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>
# include <string>
# include <sstream>

class PhoneBook
{
    private:
        int     is_empty;
        Contact mycontacts[8];
        int     get_input(void) const;
        std::string getIndex(std::string str);
    
    public:
        PhoneBook();
        ~PhoneBook();
        bool    add(void);
        void    display_contacts(void) const;
        void    search(void) const;
        void    start(void) const;
        std::string trim_space(std::string str);
        int         searchCon(void);
        int         printContact(std::string const input);
        bool        allDigits(const std::string str);
};


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:44:13 by aandom            #+#    #+#             */
/*   Updated: 2023/08/21 12:44:13 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
#include <iomanip>
# include <limits>
#include <cstdlib>


class Contact 
{

    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkSecret;
        int         index;
        bool        isvalid;
        std::string read_input(std::string  str);
        std::string updated_str(std::string str) const;

    public:
        Contact();
        ~Contact();

        bool    start_input(void);
        void    view(int    index) const;
        void    display(int    index) const;
        void    set_index(int   i);


        std::string	get_fname(void) const;
        std::string	get_lname(void) const;
        std::string	get_nname(void) const;
        std::string	get_phonenum(void) const;
        std::string	get_dsecret(void) const;
        bool        validate_input(std::string str);
        bool        check_input(std::string str);
        bool        validate_phone(std::string str);
        bool        check_phone(std::string str);
        std::string trim_sp(std::string str);

        void        set_fname(std::string str) const;
        void        set_lname(std::string str) const;
        void        set_nname(std::string str) const;
        void        set_phonenum(std::string str) const;
        void        set_dsecret(std::string str) const;

        


};


# endif
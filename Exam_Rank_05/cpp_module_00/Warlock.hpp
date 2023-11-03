/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:05:13 by aandom            #+#    #+#             */
/*   Updated: 2023/11/01 11:05:13 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
    public:
        Warlock( std::string const & name , std::string const & title);
        ~Warlock();

         std::string const   &getName () const ;
         std::string const   &getTitle () const ;

         void   setTitle (std::string const & title );
         void introduce() const;


    private:
        std::string _name;
        std::string _title;

        Warlock(Warlock const & src);;
        Warlock &  operator=(Warlock const & src);
        Warlock();
};



# endif 

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
# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Fwoosh.hpp"
# include "Dummy.hpp"
# include <algorithm>
# include <map>

class ASpell;
class ATarget;

class Warlock
{
    public:
        Warlock( std::string const & name , std::string const & title);
        ~Warlock();

        std::string const   &getName () const ;
        std::string const   &getTitle () const ;

        void   setTitle (std::string const & title );
        void introduce() const;

        void learnSpell(ASpell * src);
        void forgetSpell(std::string sname);
        void launchSpell(std::string sname, ATarget & tar);


    private:
        std::string _name;
        std::string _title;
        // ASpell * _spells[100];
        std::map<std::string, ASpell *> _spells;
        
        Warlock &  operator=(Warlock const & src);
        Warlock();
        Warlock(Warlock const & src);


        void	_initWarlock(void);
        void	_removeWarlock(void);
};



# endif 

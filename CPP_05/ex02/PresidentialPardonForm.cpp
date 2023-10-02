/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 02:20:48 by aandom            #+#    #+#             */
/*   Updated: 2023/10/03 02:32:38 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : Form("PresidentialPardonForm", 25, 5),
                                                                             _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : Form(src),
                                                                             _target(src._target) {    
}


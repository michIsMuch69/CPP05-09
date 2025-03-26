/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:24 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/26 15:55:02 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
// #include "Bureaucrat.hpp"

// one parameter in their constructor: the target of the form
#ifndef PRESIDENTIAL_PARDON_FROM_HPP
#define PRESIDENTIAL_PARDON_FROM_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sstream>

#include "Bureaucrat.hpp"
#include "AForm.hpp" // ??

class PresidentialPardonForm : public AForm
{
    private :
        std::string _target;
    public :
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm (const PresidentialPardonForm &);
        PresidentialPardonForm& operator=( const PresidentialPardonForm &);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const &executor) const;      
};
    std::ostream& operator<<(std::ostream &o, const PresidentialPardonForm &i);

#endif
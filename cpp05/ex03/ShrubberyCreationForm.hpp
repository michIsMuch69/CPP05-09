/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:35 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/26 15:55:13 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string _target;
    public :
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm (const ShrubberyCreationForm &);
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm &);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const &executor) const;
}; 
    std::ostream& operator<<(std::ostream &o, const ShrubberyCreationForm &i);

#endif
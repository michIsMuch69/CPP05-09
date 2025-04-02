/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:59:57 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 08:59:58 by jedusser         ###   ########.fr       */
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
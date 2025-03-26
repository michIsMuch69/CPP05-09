/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:30 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/26 15:39:19 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// one parameter in their constructor: the target of the form
#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>

#include "Bureaucrat.hpp"
#include "AForm.hpp" // ??

class RobotomyRequestForm : public AForm
{
    private :
        std::string _target;
    public :
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm (const RobotomyRequestForm &);
        RobotomyRequestForm& operator=( const RobotomyRequestForm &);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const &executor) const;

        
};
    
    
    std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm &i);

#endif
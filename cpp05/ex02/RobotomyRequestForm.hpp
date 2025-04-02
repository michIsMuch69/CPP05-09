/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:58:35 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 08:58:37 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "AForm.hpp"

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
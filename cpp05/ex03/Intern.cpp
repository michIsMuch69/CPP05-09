/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:27 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/26 19:09:45 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
   *this = other;
}
Intern& Intern::operator=(const Intern &other)
{
    if (this != &other)
    {

    }
    return (*this);
}
Intern::~Intern(){};


AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    if (name == "Presidential Pardon")
    {
        std::cout << "Intern creates Presidential Pardon Form\n";
        return new PresidentialPardonForm(target);
    }
    else if (name == "Shrubbery Creation")
    {
        std::cout << "Intern creates Shrubbery Creation Form\n"; 
        return new ShrubberyCreationForm(target);
        
    }
    else if (name == "Robotomy Request")
    {
        std::cout << "Intern creates Robotomy Request Form\n";
        return new RobotomyRequestForm(target);
    }
    else
    {
        std::cerr << "Error: Unknown form type\n";
        return (NULL);
    }
}
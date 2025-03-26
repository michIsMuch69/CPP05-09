/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:20 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/26 12:35:23 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.



PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
    AForm("Presidential Pardon", 25, 5), _target(target)
{
    std::cout << "PPF constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    // is an concrete class attribute copy missing ?
    std::cout << "PPF copy constructor called " << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target =  other._target;
        std::cout << "PPF assignment operator called" << std::endl;
    }
    return (*this); 
}

PresidentialPardonForm::~PresidentialPardonForm() {};
//own impl of execute virtual from base class
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() >= this->getGradeRequiredExec())
    {
        std::ostringstream oss;
        oss << "Bureaucrat [" << executor.getName()
            << "] with grade [" << executor.getGrade()
            << "] cannot execute form [" << this->getName()
            << "] because required grade is [" << this->getGradeRequiredExec() << "].";
        throw (Bureaucrat::gradeTooLowException(oss.str()));
    }
    std::cout   << this->_target
                    << " has been pardoned by Zaphod Beeblebrox." 
                    << std::endl;    
}
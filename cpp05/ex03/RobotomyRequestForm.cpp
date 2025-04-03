/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:59:41 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 11:32:47 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
    AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "SC constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    // is an concrete class attribute copy missing ?
    std::cout << "SC copy constructor called " << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target =  other._target;
        std::cout << "SC assignment operator called" << std::endl;
    }
    return (*this); 
}

RobotomyRequestForm::~RobotomyRequestForm() {};
//own impl of execute virtual from base class
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() > this->getGradeRequiredExec())
    {
        std::ostringstream oss;
        oss << "Bureaucrat [" << executor.getName()
            << "] with grade [" << executor.getGrade()
            << "] cannot execute form [" << this->getName()
            << "] because required grade is [" << this->getGradeRequiredExec() << "].";
        throw (GradeTooLowException(oss.str()));
    }
    std::cout << "🔩 BZZZZT 🔩 VRRRR 🔩 DRILLING... 🔩\n";
    srand(getpid());
    bool success = (rand() % 2);
    if (success)
        std::cout << _target << " has been robotomized\n";
    else
        std::cout << "Robotomy failed!\n";
}
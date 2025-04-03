/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:56:47 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 11:33:11 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int &grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw (GradeTooLowException("Grade must be between 1 and 150."));
    if (grade > 150)
        throw(GradeTooHighException("Grade must be between 1 and 150."));
    std::cout   << "Bureaucrat "
                << name 
                <<" Constructor called"
                << std::endl;

}

Bureaucrat::~Bureaucrat()
{
    std::cout   << "Bureaucrat "
                << _name
                << " Destructor Called"
                << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : 
_name(other._name),
_grade(other._grade)
{  
    std::cout   << "Bureaucrat " << _name
    << " Copy constructor called"
    << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        _grade = other._grade;
    }
    return (*this);
}

const int& Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o   << i.getName()
        << ", bureaucrat grade "
        << i.getGrade() << std::endl;
    return (o);
}


void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw(GradeTooHighException("Grade is already at his maximum."));
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw(GradeTooLowException("Grade is already at his minimum."));
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
    if (form.getFormStatus() == false)
    {
        std::ostringstream oss;
        oss << "Bureaucrat [" << _name
            << "] with grade [" <<_grade
            << "] cannot execute form [" << form.getName( )
            << "] because form status is [" << (form.getFormStatus() == 0 ? "Not Signed" : "Signed") << "].";
        throw (AForm::formNotSignedException(oss.str()));
    }
    
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
}
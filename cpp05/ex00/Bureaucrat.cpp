/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:13 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 10:41:59 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat Default Constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int &grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw (gradeTooLowException("Grade must be between 1 and 150."));
    if (grade > 150)
        throw(gradeTooHighException("Grade must be between 1 and 150."));
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
        _grade = other._grade;
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
        throw(gradeTooHighException("Grade is already at his maximum."));
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw(gradeTooLowException("Grade is already at his minimum."));
    this->_grade++;
}

///
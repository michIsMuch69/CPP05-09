/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:13 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/18 16:47:11 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat Default Constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(const std::string& name, const int &grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw (gradeTooLowException("Grade is too low in construct."));
    if (grade > 150)
        throw(gradeTooHighException("Grade is too high in construct."));
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
        _name = other._name;
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
        throw(gradeTooHighException("Grade is already at his maximum,"));
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw(gradeTooLowException("Grade is at his minimum"));
    this->_grade++;
}
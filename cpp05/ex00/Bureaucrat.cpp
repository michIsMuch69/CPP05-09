/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:13 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/17 12:49:27 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat Default Constructor called." << std::endl;
};

Bureaucrat::Bureaucrat(const std::string& name, const int &grade) : _name(name), _grade(grade)
{
    if(grade < 1)
        throw (gradeTooLowException("Grade is too low in construct."));
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

const int& Bureaucrat::getGrade() const
{
    return (this->_grade);
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

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o   << i.getName()
        << ", bureaucrat grade "
        << i.getGrade();
    return (o);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:13 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/13 15:07:35 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int &grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat Constructor called" << std::endl;

}

Bureaucrat::~Bureaucrat(){}

const int& Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
    o << i.getGrade();
    return (o);
}
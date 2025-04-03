/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:42:42 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 11:34:00 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeException::GradeException(const std::string &message) throw() : _message(message) {}
Bureaucrat::GradeException::~GradeException() throw(){}
const char* Bureaucrat::GradeException::what() const throw()
{
    return (_message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &message) throw() : GradeException("grade too low : " + message) {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) throw() : GradeException("grade too high : " + message) {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:42:42 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 16:15:34 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::gradeException::gradeException(const std::string &message) throw() : _message(message) {}
Bureaucrat::gradeException::~gradeException() throw(){}
const char* Bureaucrat::gradeException::what() const throw()
{
    return (_message.c_str());
}

Bureaucrat::gradeTooLowException::gradeTooLowException(const std::string &message) throw() : gradeException("grade too low : " + message) {}
Bureaucrat::gradeTooLowException::~gradeTooLowException() throw(){}

Bureaucrat::gradeTooHighException::gradeTooHighException(const std::string &message) throw() : gradeException("grade too high : " + message) {}
Bureaucrat::gradeTooHighException::~gradeTooHighException() throw(){}




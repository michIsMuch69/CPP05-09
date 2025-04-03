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
#include "AForm.hpp"

//################### Bureaucrat Exceptions Implementation ###################//

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

//################### AForm Exceptions Implementation ###################//

AForm::GradeException::GradeException(const std::string &message) throw() : _message(message) {}
AForm::GradeException::~GradeException() throw(){}
const char* AForm::GradeException::what() const throw()
{
    return (_message.c_str());
}

AForm::gradeTooLowException::gradeTooLowException(const std::string &message) throw() : GradeException("grade too low : " + message) {}
AForm::gradeTooLowException::~gradeTooLowException() throw(){}

AForm::gradeTooHighException::gradeTooHighException(const std::string &message) throw() : GradeException("grade too high : " + message) {}
AForm::gradeTooHighException::~gradeTooHighException() throw(){}

AForm::formNotSignedException::formNotSignedException(const std::string &message) throw() : _message(message) {}
AForm::formNotSignedException::~formNotSignedException() throw() {}
const char * AForm::formNotSignedException::what() const throw()
{
    return (_message.c_str());
} 







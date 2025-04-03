/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:12:55 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 11:33:11 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, const int& grade_required_sign, const int& grade_required_exec)
        :   _name(name), _formStatus(false), 
            _grade_required_sign(grade_required_sign),
            _grade_required_exec(grade_required_exec)
{
    if (_grade_required_exec < 1 || grade_required_sign < 1)
        throw(Bureaucrat::GradeTooLowException("Grade too low, must be between 1 and 150."));
    if (_grade_required_exec > 150 || grade_required_sign > 150)
        throw(Bureaucrat::GradeTooHighException("Grade too high must be between 1 and 150."));
    std::cout   << "Form "  
                << name 
                << " Constructor called." 
                << std::endl;
}

Form::Form(const Form &other) 
: _name(other._name), _formStatus(other._formStatus),
    _grade_required_sign(other._grade_required_sign),
    _grade_required_exec(other._grade_required_exec) 
{
    std::cout << "Form Copy Constructor called." << std::endl;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        _formStatus = other._formStatus;
    return (*this);    
}

std::ostream& operator<<(std::ostream &o, const Form &i)
{
        o   << "Form : " 
            << i.getName() << std::endl
            << "Status :";
        
        if (i.getFormStatus() == true)
            o << "SIGNED" << std::endl;
        else
            o << "NOT SIGNED" << std::endl;
            
        o   << "Grade required for signing : "
            << i.getGradeRequiredSign() << std::endl
            << "Grade required for execution : "
            << i.getGradeRequiredExec() << std::endl;

        return (o);
}

Form::~Form(){};

void Form::beSigned(const Bureaucrat& bc)
{
    if (bc.getGrade() > this->_grade_required_sign) 
    {
        std::ostringstream oss;
        oss << "Bureaucrat [" << bc.getName() 
            << "] with grade [" << bc.getGrade()
            << "] cannot sign form [" << this->_name 
            << "] because required grade is [" << this->_grade_required_sign << "].";

        throw(Bureaucrat::GradeTooLowException(oss.str()));

    }
    this->_formStatus = true;
}


const std::string& Form::getName() const
{
    return (this->_name);
}

const bool& Form::getFormStatus() const
{
    return(this->_formStatus);
}

const int& Form::getGradeRequiredSign() const
{
    return (this->_grade_required_sign);
}

const int& Form::getGradeRequiredExec() const
{
    return (this->_grade_required_exec);
}
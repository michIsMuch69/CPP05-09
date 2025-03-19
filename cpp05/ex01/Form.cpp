/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:12:55 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/19 13:27:09 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, bool& formStatus, const int& grade_required_sign, const int& grade_required_exec)
        :   _name(name), _formStatus(formStatus), 
            _grade_required_sign(grade_required_sign),
            _grade_required_exec(grade_required_exec)
{
    std::cout << "Form Default Constructor called." << std::endl;
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
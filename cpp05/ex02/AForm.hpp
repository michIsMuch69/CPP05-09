/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:12:58 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/20 19:26:13 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sstream>

class Bureaucrat;

// Keep in mind the form’s attributes need to remain private and that
// they are in the base class.

class AForm
{
    private :
        const std::string _name;
        bool  _formStatus;
        const int _grade_required_sign;
        const int _grade_required_exec;
        
    public :
        AForm(const std::string& name, const int& grade_required_sign, const int& grade_required_exec);
        AForm(const AForm&);
        AForm& operator=(const AForm&);
        ~AForm();
        
        const std::string& getName() const;
        const bool& getFormStatus() const;
        const int& getGradeRequiredSign() const;
        const int& getGradeRequiredExec() const;

        void beSigned(const Bureaucrat &);

//         (Bureaucrat const & executor) const member function to
// the base form and implement a function to execute the form’s action of the concrete
// classes


        //###################Exception Classes###################

        class gradeTooLowException : public std::exception
        {
            protected :
                std::string _message;
            public :
                gradeTooLowException(const std::string& message) throw() : _message(message){}
                virtual ~gradeTooLowException() throw() {}
                virtual const char* what()  const throw()
                {
                    return _message.c_str();
                }
            };

        class gradeTooHighException : virtual public gradeTooLowException
        {
            public :
                gradeTooHighException(const std::string& message) throw() : gradeTooLowException(message){}
                virtual ~gradeTooHighException() throw() {}
        };
        //###################Exception Classes###################//
        

        // class gradeTooLowException
          
};

std::ostream& operator<<(std::ostream &o, const AForm &i);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-micheldusserre <jean-micheldusserr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:12:58 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/20 18:55:26 by jean-michel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

class Bureaucrat;

class Form
{
    private :
        const std::string _name;
        bool  _formStatus;
        const int _grade_required_sign;
        const int _grade_required_exec;
        
    public :
        Form(const std::string& name, bool& formStatus, const int& grade_required_sign, const int& grade_required_exec);
        Form(const Form&);
        Form& operator=(const Form&);
        ~Form();
        
        const std::string& getName() const;
        const bool& getFormStatus() const;
        const int& getGradeRequiredSign() const;
        const int& getGradeRequiredExec() const;

        void beSigned(const Bureaucrat &);

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

std::ostream& operator<<(std::ostream &o, const Form &i);


#endif

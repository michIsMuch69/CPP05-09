/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:56:36 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 09:35:05 by jedusser         ###   ########.fr       */
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
        virtual ~AForm();
        
        const std::string& getName() const;
        const bool& getFormStatus() const;
        const int& getGradeRequiredSign() const;
        const int& getGradeRequiredExec() const;
        
        void beSigned(const Bureaucrat &);
        virtual void execute(Bureaucrat const &executor) const =0;

        //###################Exception Classes###################//
        class gradeException : public std::exception
        {
            protected:
                std::string _message;
            public:
                gradeException(const std::string &message) throw() : _message(message) {}
                virtual ~gradeException() throw() {}
                virtual const char* what() const throw() { return _message.c_str(); }
        };

        class gradeTooLowException : public gradeException
        {
            public:
                gradeTooLowException(const std::string &message) throw() : gradeException(message) {}
                virtual ~gradeTooLowException() throw() {}
        };

        class gradeTooHighException : public gradeException
        {
            public:
                gradeTooHighException(const std::string &message) throw() : gradeException(message) {}
                virtual ~gradeTooHighException() throw() {}
        };
        class formNotSignedException : public std::exception
        {
            protected:
                std::string _message;
            public:
                formNotSignedException(const std::string &message) throw() : _message(message) {}
                virtual ~formNotSignedException() throw() {}
                virtual const char* what() const throw() { return _message.c_str(); }
        };
        
        //###################Exception Classes###################//
};

std::ostream& operator<<(std::ostream &o, const AForm &i);


#endif

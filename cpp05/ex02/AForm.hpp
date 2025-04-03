/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:56:36 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 11:34:00 by jedusser         ###   ########.fr       */
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
        
        class GradeException : public std::exception
        {
            protected:
                std::string _message;
            public:
                GradeException(const std::string &message) throw();
                virtual ~GradeException() throw();
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public GradeException
        {
            public:
                GradeTooLowException(const std::string &message) throw();
                virtual ~GradeTooLowException() throw();
        };

        class GradeTooHighException : public GradeException
        {
            public:
                GradeTooHighException(const std::string &message) throw();
                virtual ~GradeTooHighException() throw();
        };
        class formNotSignedException : public std::exception
        {
            protected:
                std::string _message;
            public:
                formNotSignedException(const std::string &message) throw();
                virtual ~formNotSignedException() throw();
                const char* what() const throw();
        };
        
        //###################Exception Classes###################//
};

std::ostream& operator<<(std::ostream &o, const AForm &i);


#endif

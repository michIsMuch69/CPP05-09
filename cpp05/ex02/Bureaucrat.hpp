/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:16 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/26 11:59:09 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

class AForm;

class Bureaucrat
{
    private : 
    
        const std::string _name;
        int     _grade;
        
    public :

        
        Bureaucrat();

        Bureaucrat(const std::string &name, const int &grade);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        
        ~Bureaucrat();
        
        void incrementGrade();
        void decrementGrade();
        
        const int &getGrade() const;
        const std::string& getName() const;

        void signForm(AForm &form);
        void executeForm(AForm const &form);
        

        //###################Exception Classes###################
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
        //###################Exception Classes###################//

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
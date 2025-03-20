/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-micheldusserre <jean-micheldusserr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:16 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/20 11:39:54 by jean-michel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Form.hpp"

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

        void signForm(Form &form);
        

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

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
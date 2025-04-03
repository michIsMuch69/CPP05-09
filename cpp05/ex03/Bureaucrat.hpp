/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:59:05 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 11:34:00 by jedusser         ###   ########.fr       */
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
        //###################Exception Classes###################//

};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
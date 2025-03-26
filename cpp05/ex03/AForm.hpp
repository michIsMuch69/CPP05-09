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

        //###################Exception Classes###################

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

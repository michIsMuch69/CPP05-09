/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:16 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/17 13:05:33 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstring>

class Bureaucrat
{
    private : 
        std::string _name;
        int     _grade;

    public :
        Bureaucrat();
        Bureaucrat(const std::string &name, const int &grade);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        
        class gradeTooLowException : public std::exception
        {
            private :
            std::string _message;
          public :
            gradeTooLowException(const std::string& message) throw() : _message(message){}
            virtual ~gradeTooLowException() throw() {}
            virtual const char* what()  const throw()
            {
                return _message.c_str();
            }
        };
        
        ~Bureaucrat();

        

        void incrementGrade(int grade);
        void decrementGrade(int grade);

        const int &getGrade() const;
        const std::string& getName() const;


};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
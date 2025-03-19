/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:12:58 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/19 14:00:20 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

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
          
};

std::ostream& operator<<(std::ostream &o, const Form &i);


#endif

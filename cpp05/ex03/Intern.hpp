/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:05:30 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/26 18:01:15 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"


// However, the intern has one important capacity: the makeForm() function.
// It takes two strings.
// The first one is the name of a form and the second one is the target of the
// form.
// It return a pointer to a Form object (whose name is the one passed as parameter)
// whose target will be initialized to the second parameter.
// It will print something like:
// Intern creates <form>
// If the form name passed as parameter doesn’t exist, print an explicit error message

class Intern
{
    public :                 
        Intern();
        Intern(const Intern &);
        Intern& operator=(const Intern &);
        ~Intern();
        
        AForm* makeForm(const std::string &name, const std::string& target);

    
};

#endif
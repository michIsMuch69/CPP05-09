/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:59:15 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 08:59:17 by jedusser         ###   ########.fr       */
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
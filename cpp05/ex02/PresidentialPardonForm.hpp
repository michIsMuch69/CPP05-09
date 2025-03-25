/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:24 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/25 13:39:14 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AForm.hpp"
// #include "Bureaucrat.hpp"

// one parameter in their constructor: the target of the form


#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sstream>

class Bureaucrat;
class AForm;
#include "AForm.hpp" // ??

class PresidentialPardonForm : public AForm
{
    private :
        const std::string target;
    public :
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm (const PresidentialPardonForm &);
        PresidentialPardonForm& operator=( const PresidentialPardonForm &);
        ~PresidentialPardonForm();

        
};
    
    
    std::ostream& operator<<(std::ostream &o, const PresidentialPardonForm &i);
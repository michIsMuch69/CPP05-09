/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:20 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/25 13:38:28 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

class AForm;

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
    AForm("PPF", 25, 5)
{
    std::cout << "PPF constructor called" << std::endl;
}
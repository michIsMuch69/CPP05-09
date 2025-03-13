/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:16 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/13 15:06:28 by jedusser         ###   ########.fr       */
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
        const   std::string _name;
        int     _grade;

    public :
        Bureaucrat(const std::string &name, const int &grade);
        ~Bureaucrat();
        void increment(int grade);
        void decrement(int grade);
        const int &getGrade() const;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
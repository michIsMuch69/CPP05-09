/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:21:44 by michismuch        #+#    #+#             */
/*   Updated: 2025/03/25 13:33:13 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int runProgram()
{
    Bureaucrat* bc = NULL;
    AForm* f = NULL;
    try
    {
        bc = new Bureaucrat("joe", 5);  // peut throw une except.
        std::cout << *bc << std::endl;
    
        f = new AForm("B52", 5, 19);  // peut throw une excapt
        std::cout << *f << std::endl;
    
        f->beSigned(*bc);
        std::cout << *f << std::endl;


        bc->decrementGrade();
        f->beSigned(*bc);
        std::cout << *f << std::endl;

    
        delete bc;
        delete f;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        delete bc;
        delete f;
        return 1;
    }
}

int main()
{
    return runProgram();
}


    // Bureaucrat::GradeTooHighException
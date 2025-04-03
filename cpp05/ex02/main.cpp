/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:58:02 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 10:39:54 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int runProgram()
{
    Bureaucrat* bc = NULL;
    AForm* f = NULL;
    try
    {
        bc = new Bureaucrat("Joe", 1530);//ut throw une except.
        std::cout << *bc << std::endl;
    
        f = new PresidentialPardonForm("Bill");  // peut throw une excapt
        std::cout << *f << std::endl;
        bc->signForm(*f);
        std::cout << *f << std::endl;
        bc->executeForm(*f);
        delete(f);

        f = new ShrubberyCreationForm("Home");//peut throw une except
        std::cout << *f << std::endl;   
        bc->signForm(*f);
        std::cout << *f << std::endl;
        bc->executeForm(*f);
        delete(f);

        
        f = new RobotomyRequestForm("Bender");  // peut throw une excapt
        std::cout << *f << std::endl;
        bc->signForm(*f);
        std::cout << *f << std::endl;
        bc->executeForm(*f);

        
        // f->beSigned(*bc);
        // std::cout << *f << std::endl;
        // f->execute(*bc);
        // std::cout << *f << std::endl;


        // bc->decrementGrade();
        // f->beSigned(*bc);
        // std::cout << *f << std::endl;

    
        delete bc;
        delete f;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Error: " << RESET << e.what() << std::endl;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:59:20 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 10:37:35 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int runProgram()
{
    Bureaucrat* bc = NULL;
    AForm* f = NULL;
    Intern *i = NULL;
    try
    {
        bc = new Bureaucrat("Joe", 1);// peut throw une except.
        std::cout << *bc << std::endl;
    
        // f = new PresidentialPardonForm("Bill");  // peut throw une excapt
        // std::cout << *f << std::endl;
        // bc->signForm(*f);
        // std::cout << *f << std::endl;
        // bc->executeForm(*f);

        // f = new ShrubberyCreationForm("Shrub");  // peut throw une excapt
        // std::cout << *f << std::endl;
        // bc->signForm(*f);
        // std::cout << *f << std::endl;
        // bc->executeForm(*f);
        
        // f = new RobotomyRequestForm("Bender");  // peut throw une excapt
        // std::cout << *f << std::endl;
        // bc->signForm(*f);
        // std::cout << *f << std::endl;
        // bc->executeForm(*f);
        f = i->makeForm("Shrubbery Creation", "Home");
        bc->signForm(*f);
        bc->executeForm(*f);
        delete(f);
        
        f = i->makeForm("Presidential Pardon", "L.H.Oswald");
        bc->signForm(*f);
        bc->executeForm(*f);
        delete(f);

        f = i->makeForm("Robotomy Request", "Bender");
        bc->signForm(*f);
        bc->executeForm(*f);
        //std::cout << i;
        
        
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:56:16 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 08:56:21 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int runProgram()
{
    Bureaucrat* bc = NULL;
    Form* f = NULL;
    try
    {
        bc = new Bureaucrat("joe", 5);  // peut throw une except.
        std::cout << *bc << std::endl;
    
        f = new Form("B52", 5, 19);  // peut throw une excapt
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
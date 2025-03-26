  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:18 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/20 19:32:42 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int runProgram()
{
    Bureaucrat* bc = NULL;
    try
    {
        bc = new Bureaucrat("joe", 151);  // peut throw une except.
        std::cout << *bc << std::endl;
    
       
        bc->decrementGrade();
        std::cout << *bc << std::endl;

        bc->incrementGrade();
        std::cout << *bc << std::endl;

        delete bc;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        delete bc;
        return 1;
    }
}

int main()
{
    return runProgram();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:55:39 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 13:38:22 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int runProgram()
{
    Bureaucrat* bc = NULL;
    try
    {
        bc = new Bureaucrat("joe", 150);//ut throw une except.
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

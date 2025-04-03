/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:55:39 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/03 10:51:00 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "colors.hpp"

int runProgram()
{
    std::cout << CYAN << "===== START OF TESTS =====" << RESET << std::endl;

    Bureaucrat* bc = NULL;

    std::cout << YELLOW << "\n>> Testing creation with an invalid grade (151):" << RESET << std::endl;
    try
    {
        bc = new Bureaucrat("Joe", 151); // Devrait lever une exception
        std::cout << GREEN << "✓ Creation succeeded (this should not happen!)" << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "✗ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n>> Testing creation with a valid grade (42):" << RESET << std::endl;
    try
    {
        bc = new Bureaucrat("Alice", 42);
        std::cout << GREEN << "✓ Bureaucrat successfully created: " << RESET << *bc << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "✗ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n>> Testing grade decrement beyond limit (grade 150):" << RESET << std::endl;
    try
    {
        Bureaucrat lowRank("Bob", 150);
        lowRank.decrementGrade(); // Devrait lever une exception
        std::cout << GREEN << "✓ Decrement succeeded (this should not happen!)" << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "✗ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << YELLOW << "\n>> Testing grade increment beyond limit (grade 1):" << RESET << std::endl;
    try
    {
        Bureaucrat topRank("Charlie", 1);
        topRank.incrementGrade(); // Devrait lever une exception
        std::cout << GREEN << "✓ Increment succeeded (this should not happen!)" << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "✗ Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "\n>> Testing normal increment and decrement:" << RESET << std::endl;
    try
    {
        Bureaucrat normal("David", 50);
        std::cout << GREEN << "✓ Initial state: " << RESET << normal << std::endl;

        normal.incrementGrade();
        std::cout << GREEN << "✓ After increment: " << RESET << normal << std::endl;

        normal.decrementGrade();
        std::cout << GREEN << "✓ After decrement: " << RESET << normal << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "✗ Unexpected exception: " << e.what() << RESET << std::endl;
    }

    delete bc;

    std::cout << CYAN << "\n===== END OF TESTS =====" << RESET << std::endl;
    return 0;
}



int main()
{
    return runProgram();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:18 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/18 16:52:59 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// void createBureaucrat(const std::string& name, const int& grade)
// {
//     // Bureaucrat *bc = NULL;
    
// }

int main(int argc, char **argv)
{
    if (argc == 3)
    {

        
        std::string name = argv[1];
        int grade = atoi(argv[2]);

        Bureaucrat *bc = NULL;

    
        try
        {
            bc = new Bureaucrat(name, grade);
            
            std::cout << *bc;
            bc->incrementGrade();
            std::cout << *bc;

            // bc->decrementGrade();
            // std::cout << *bc;
            
        }
        catch (const Bureaucrat::gradeTooLowException& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch(const Bureaucrat::gradeTooHighException& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        delete (bc);
    }
    return (0);
    
}
// Bureaucrat::GradeTooHighException
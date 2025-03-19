/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:18 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/19 14:01:40 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// void createBureaucrat(const std::string& name, const int& grade)
// {
//     // Bureaucrat *bc = NULL;
    
// }

int main(int argc, char **argv)
{
    const std::string name = "B28";
    const int grs = 25;
    const int gre = 32;
    bool fs = false;
    Form form(name, fs, grs, gre);

    std::cout << form << std::endl;

    
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

            bc->decrementGrade();
            std::cout << *bc;
            
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
    else
    {
        std::cout   << "Invalid entry: "
                    << "Usage: <executable> <bureaucrat name> <bureaucrat grade>"
                    << std::endl;
    }
    return (0);
    
}
// Bureaucrat::GradeTooHighException
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:18 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/19 21:02:38 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// void createBureaucrat(const std::string& name, const int& grade)
// {
//     // Bureaucrat *bc = NULL;
    
// }

/* A CORRIGER :

    -name mst be cost
    - didn't have chance to test because : 
        - error: main.cpp: In function ‘int main(int, char**)’:
            main.cpp:50:9: error: exception of type ‘Bureaucrat::gradeTooHighException’ will be caught by earlier handler [-Werror=exceptions]
            50 |         catch(const Bureaucrat::gradeTooHighException& e)
                |         ^~~~~
            main.cpp:46:9: note: for type ‘Bureaucrat::gradeTooLowException’
            46 |         catch (const Bureaucrat::gradeTooLowException& e)
                |         ^~~~~
            cc1plus: all warnings being treated as errors
            make: *** [Makefile:37: obj/main.o] Error 1)
    - corriger ex01 en fonction
*/

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
            
            bc->incrementGrade(); //promote
            std::cout << *bc;

            bc->decrementGrade(); //demote
            std::cout << *bc;
            
        }
        catch(const Bureaucrat::gradeTooHighException& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
        catch (const Bureaucrat::gradeTooLowException& e)
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
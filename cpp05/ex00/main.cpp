/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:38:18 by jedusser          #+#    #+#             */
/*   Updated: 2025/03/17 13:05:00 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::string name = "Joe";
    int grade = 0;
    
    Bureaucrat *bc2 = NULL;
    
    try
    {
        bc2 = new Bureaucrat(name, grade);
        // ddddd
        std::cout << *bc2;
    }
    catch (const Bureaucrat::gradeTooLowException& e)
    {
        std::cout << "Erreur : " << e.what() << std::endl;
        return 0;
    }
    // catch (std::range_error &e)
    // {
        
    // }
    
    // if (bc2 != NULL)
    
}
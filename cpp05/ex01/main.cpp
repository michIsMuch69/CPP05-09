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
    #include "Form.hpp"

    // void createBureaucrat(const std::string& name, const int& grade)
    // {
    //     // Bureaucrat *bc = NULL;
        
    // }

    Bureaucrat* createBureaucrat(const std::string &name, const int &grade)
    {
        Bureaucrat *bc = NULL;
        try
        {
            bc = new Bureaucrat(name, grade);
            //std::cout << *bc;
            
            // bc->incrementGrade();
            // std::cout << *bc;
            
            // bc->decrementGrade();
            // std::cout << *bc;
            return (bc);
            
        }
        catch(const Bureaucrat::gradeTooHighException& e)
        {
            std::cout << "Error: Bureaucrat not created: " << e.what() << std::endl;
            return (bc);
        }
        catch (const Bureaucrat::gradeTooLowException& e)
        {
            std::cout << "Error: Bureaucrat not created: " << e.what() << std::endl;
            return (bc);
        }
    }

    Form* createForm(const std::string& name, bool& formStatus, const int& grade_required_sign, const int& grade_required_exec)
    {
        Form *f = NULL;
        try
        {
            f = new Form(name, formStatus, grade_required_sign, grade_required_exec);
            
            std::cout << *f << std::endl;
            return (f);
            /* code */
        }
        catch(Form::gradeTooHighException &e)
        {
            std::cout << "Error: Form ["<< name << "] not created: " << e.what() << std::endl;
            return (f);
        }
        catch(Form::gradeTooLowException &e)
        {
            std::cout << "Error: Form ["<< name << "] not created: " << e.what() << std::endl;
            return (f);
        }
        
    }

    int main()
    {
        Bureaucrat *bc = createBureaucrat("joe", 0);
        if (bc)
        std::cout << *bc << std::endl;


        bool isSigned = false;
        Form *f = createForm("B52", isSigned , 5, 19);
        if (f && bc)
        {
            try 
            {
                f->beSigned(*bc);
            }
            catch (Form::gradeTooLowException &e )
            {
                std::cout << "Error, form not signed: " << e.what() << std::endl;
            }

            std::cout << *f << std::endl;

        }
            
        delete(bc);
        delete(f);
        return (0);
        
    }
    // Bureaucrat::GradeTooHighException
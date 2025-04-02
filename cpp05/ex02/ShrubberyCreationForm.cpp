/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:57:33 by jedusser          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:14 by jedusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// • ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it.


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
    AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "SC constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    // is an concrete class attribute copy missing ?
    std::cout << "SC copy constructor called " << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target =  other._target;
        std::cout << "SC assignment operator called" << std::endl;
    }
    return (*this); 
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};
//own impl of execute virtual from base class
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (executor.getGrade() >= this->getGradeRequiredExec())
    {
        std::ostringstream oss;
        oss << "Bureaucrat [" << executor.getName()
            << "] with grade [" << executor.getGrade()
            << "] cannot execute form [" << this->getName()
            << "] because required grade is [" << this->getGradeRequiredExec() << "].";
        throw (gradeTooLowException(oss.str()));
    }

    
    
    std::ifstream tree_file("tree.txt", std::ifstream::in);
    if (!tree_file)
    {
        std::cerr << "File : <" << "tree.txt" <<  "> does not exists." << std::endl;
        return ;
    }

    
    std::string filename = _target + "_shrubbery";
    std::ofstream dest_file(filename.c_str());
    std::string src_line;
    std::string string = "  ";  
    while(std::getline(tree_file, src_line))
    {
        if (!src_line.empty())
            dest_file << src_line << std::endl;        
    }
    std::cout << filename << "Created, take a look inside !" << std::endl;
    tree_file.close();
    dest_file.close();

}
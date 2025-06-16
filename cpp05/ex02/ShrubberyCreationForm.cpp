/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:39:17 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:33 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include  "Bureaucrat.hpp"

/**
 * @brief Executes the ShrubberyCreationForm.
 * 
 * Throws GradeTooLowException if executor's grade is too low.
 * Creates a file named "<target>_shrubbery" and writes an ASCII tree.
 * 
 * @param executor The Bureaucrat executing the form.
 */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	toWrite;
	std::string		fileName;

	if (getGradeToExecute() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	fileName = this->target + (std::string)"_shrubbery";
	toWrite.open(fileName, std::ios::out);
	if (!toWrite)
	{
		std::cout << "Can't execute ShrubberyCreationForm" << std::endl;
	}
	toWrite << " \n\
                             +\n\
                            +++\n\
                          +++++++\n\
                        +++++++++++\n\
                      +++++++++++++++\n\
                         +++++++++\n\
                       +++++++++++++\n\
                     +++++++++++++++++\n\
                   +++++++++++++++++++++\n\
                 +++++++++++++++++++++++++\n\
                    +++++++++++++++++++\n\
                  +++++++++++++++++++++++\n\
                +++++++++++++++++++++++++++\n\
              +++++++++++++++++++++++++++++++\n\
            +++++++++++++++++++++++++++++++++++\n\
          ++++++++++++++++mmmmmmm++++++++++++++++\n\
                          mmmmmmm\n\
                          mmmmmmm\n\
                          mmmmmmm\n\
                          mmmmmmm" << std::endl;
	toWrite.close();
}

/**
 * @brief Assignment operator overload.
 * 
 * Copies the target from another ShrubberyCreationForm.
 * 
 * @param before The form to copy from.
 * @return ShrubberyCreationForm& Reference to this form.
 */
ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& before)
{
	std::cout << "Copy ShrubberyCreationForm Assigment operator called" << std::endl;
	this->target = before.target;
	return (*this);
}

/**
 * @brief Copy constructor.
 * 
 * Copies this form from another instance.
 * 
 * @param before The form to copy from.
 */
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& before )
{
	std::cout << "Copy ShrubberyCreationForm Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Parameterized constructor.
 * 
 * Creates a ShrubberyCreationForm with a specific target.
 * 
 * @param target The target file prefix.
 */
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "Default ShrubberyCreationForm Constructor called" << std::endl;
}

/**
 * @brief Default constructor.
 * 
 * Creates a ShrubberyCreationForm with default target "target".
 */
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "target";
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Prints a message when the form is destructed.
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm Destructor called" << std::endl;
}

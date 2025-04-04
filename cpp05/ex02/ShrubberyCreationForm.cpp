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

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& before)
{
	std::cout << "Copy ShrubberyCreationForm Assigment operator called" << std::endl;
	this->target = before.target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& before )
{
	std::cout << "Copy ShrubberyCreationForm Constructor called" << std::endl;
	*this = before;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
	std::cout << "Default ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = "target";
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm Destructor called" << std::endl;
}



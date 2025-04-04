/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:43:41 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/05 12:43:43 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

AForm*	Intern::makeForm( std::string formName, std::string formTarget )
{
	std::string options[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int	formNum;
	for (size_t i = 0; i < 3; i++)
	{
		if (options[i] == formName)
			formNum = i;
	}
	AForm	*form =  NULL;
	switch (formNum)
	{
		case 0:
		{
			form = new PresidentialPardonForm(formTarget);
			break ;
		}
		case 1:
		{
			form = new RobotomyRequestForm(formTarget);
			break ;
		}
		case 2:
		{
			form = new ShrubberyCreationForm(formTarget);
			break ;
		}
		default:
		{
			std::cout << "Not a valid form" << std::endl;
			break;
		}
	}
	return (form);
}

Intern& Intern::operator=( const Intern& before )
{
	std::cout << "Copy Intern Assigment operator called" << std::endl;
	return (*this);
}

Intern::Intern( const Intern& before )
{
	std::cout << "Copy Interrn Constructor called" << std::endl;
	*this = before;
}

Intern::Intern( void )
{
	std::cout << "Default Intern Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Default Intern Destructor called" << std::endl;
}

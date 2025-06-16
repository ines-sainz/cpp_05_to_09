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

/**
 * @brief Creates a form of a given type and target.
 * 
 * Searches for the form name in a predefined list and dynamically allocates
 * the appropriate form type (PresidentialPardonForm, RobotomyRequestForm,
 * or ShrubberyCreationForm). If no match is found, prints an error message.
 * 
 * @param formName Name of the form to create.
 * @param formTarget Target of the created form.
 * @return AForm* Pointer to the newly created form, or NULL if invalid.
 */
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

/**
 * @brief Assignment operator for Intern.
 * 
 * Prints a message and returns a reference to the current object.
 * 
 * @param before Reference to the Intern being copied.
 * @return Intern& Reference to the current Intern object.
 */
Intern& Intern::operator=( const Intern& before )
{
	std::cout << "Copy Intern Assigment operator called" << std::endl;
	return (*this);
}

/**
 * @brief Copy constructor for Intern.
 * 
 * Calls the assignment operator to copy data from the given Intern.
 * 
 * @param before Reference to the Intern being copied.
 */
Intern::Intern( const Intern& before )
{
	std::cout << "Copy Interrn Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Default constructor for Intern.
 * 
 * Prints a message upon creation.
 */
Intern::Intern( void )
{
	std::cout << "Default Intern Constructor called" << std::endl;
}

/**
 * @brief Destructor for Intern.
 * 
 * Prints a message upon destruction.
 */
Intern::~Intern()
{
	std::cout << "Default Intern Destructor called" << std::endl;
}

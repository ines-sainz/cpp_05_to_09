/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:31:26 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:40:43 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/**
 * @brief Main function demonstrating Intern form creation and execution.
 * 
 * Creates a Bureaucrat with the highest grade, and an Intern who creates a
 * PresidentialPardonForm targeted at "random". The Bureaucrat signs and
 * executes the form. The form is deleted at the end to prevent memory leak.
 * 
 * @return int Always returns 0.
 */
int main()
{
	Bureaucrat	one("one", 1);
	AForm	*form;
	Intern	intern;

	form = intern.makeForm("PresidentialPardonForm", "random");
	one.signForm(*form);
	one.execute(*form);
	delete form;
}

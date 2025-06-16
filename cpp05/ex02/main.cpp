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

/**
 * @brief Main function demonstrating usage of Bureaucrat and Forms.
 * 
 * Creates Bureaucrats and dynamically allocates various forms:
 * PresidentialPardonForm, RobotomyRequestForm, ShrubberyCreationForm.
 * 
 * Each Bureaucrat attempts to execute, sign, re-sign, and execute the 
 * forms, with exceptions caught and error messages displayed.
 * 
 * @return int Always returns 0.
 */
int main()
{
	try
	{
		Bureaucrat	b2("b2", 1);
		AForm *pardon =   new PresidentialPardonForm("pardon");

		b2.execute(*pardon);
		b2.signForm(*pardon);
		b2.signForm(*pardon);
		b2.execute(*pardon);
		delete pardon;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat	b3("b3", 1);
		AForm *robot = new RobotomyRequestForm("robot");

		b3.execute(*robot);
		b3.signForm(*robot);
		b3.signForm(*robot);
		b3.execute(*robot);
		delete robot;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat	b4("b4", 1);
		AForm *tree = new ShrubberyCreationForm("tree");

		b4.execute(*tree);
		b4.signForm(*tree);
		b4.signForm(*tree);
		b4.execute(*tree);
		delete tree;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

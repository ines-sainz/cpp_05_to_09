/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:31:26 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/15 12:31:28 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * @brief Entry point of the program testing Form and Bureaucrat exceptions.
 * 
 * Tries to create Forms with invalid grades to catch exceptions.
 * Then creates Bureaucrats and Forms to test signing behavior.
 * 
 * @return int Always returns 0 on completion.
 */
int main()
{
	try
	{
		Form		f0("f0", 0, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Form		f01("f01", 151, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat	b1("b1", 2);
		Form		f1("f1", 1, 3);

		std::cout << f1;
		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat	b2("b2", 1);
		Form		f2("f2", 1, 3);

		b2.signForm(f2);
		b2.signForm(f2);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

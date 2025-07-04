/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:28 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/05 16:24:30 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * @brief Entry point of the program.
 *
 * Expects a single argument, which it passes to ScalarConverter for type
 * conversion. Displays an error if the number of arguments is not exactly one.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @return 0 on success, 1 on error.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Need one argument only" << std::endl;
		return (1);
	}
	ScalarConverter::convert( (std::string)argv[1] );
}

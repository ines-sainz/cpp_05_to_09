/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:14:34 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:14:38 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @brief Program entry point that checks input argument count and evaluates
 *        a Reverse Polish Notation (RPN) expression from the command line.
 *
 * Checks if exactly one argument is provided; if not, prints "Error" and
 * returns failure. Otherwise, calls reverse_polish_notation() with the
 * input string and returns 0 if successful or 1 on error.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Returns 0 on success, 1 on error.
 */
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	if (reverse_polish_notation(argv[1]) == 1)
		return (1);
	return (0);
}

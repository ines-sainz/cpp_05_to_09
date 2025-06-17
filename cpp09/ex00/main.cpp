/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:13:23 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:13:24 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Main entry point of the program.
 * 
 * Checks if the program receives exactly one argument (input file path).
 * If not, prints an error message. Calls BitcoinExchange with arguments
 * and returns its status. Returns 0 on success, 1 on error.
 * 
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Exit status code.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	if (BitcoinExchange(argv) == 1)
		return (1);
	return (0);
}

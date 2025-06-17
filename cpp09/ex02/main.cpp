/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:15:44 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:45 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Program entry point.
 * 
 * Checks for correct number of command-line arguments and calls the main
 * sorting function pmerge_me. Prints "Error" if no arguments are provided.
 * 
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Returns 0 on success, 1 on error.
 */
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	if (pmerge_me(argv) == 1)
		return (1);
	return (0);
}

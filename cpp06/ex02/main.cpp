/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:52:19 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 12:52:21 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * @brief Main function to test dynamic casting and type identification.
 *
 * Creates a randomly generated derived object (A, B, or C) using Base::generate.
 * Then identifies the type using both pointer and reference versions of 
 * Base::identify, and finally deletes the allocated object.
 *
 * @return int Exit status code.
 */
int main()
{
		Base	*base = NULL;
		base = base->generate();

		std::cout << "\n";
		base->identify(base);
		std::cout << "\n";
		base->identify(*base);
		std::cout << "\n";
		delete base;
}

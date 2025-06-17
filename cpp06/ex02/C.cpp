/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:46:06 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 12:46:07 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

/**
 * @brief Default constructor for class C.
 *
 * Prints a message when an instance of C is created.
 */
C::C( void )
{
	std::cout << "Default C Constructor called" << std::endl;
}

/**
 * @brief Default destructor for class C.
 *
 * Prints a message when an instance of C is destroyed.
 */
C::~C()
{
	std::cout << "Default C Destructor called" << std::endl;
}

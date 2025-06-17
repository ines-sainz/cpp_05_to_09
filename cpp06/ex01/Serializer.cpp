/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:49:48 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 09:49:50 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * @brief Converts an integer back to a Data pointer.
 *
 * @param raw The integer representing the pointer.
 * @return A pointer to a Data structure.
 */
Data* Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data*>(raw));
}

/**
 * @brief Converts a Data pointer to an integer type.
 *
 * @param ptr Pointer to a Data structure.
 * @return An integer representation of the pointer.
 */
uintptr_t Serializer::serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief Assignment operator for Serializer.
 *
 * @param before The Serializer instance to copy from.
 * @return Reference to this Serializer.
 */
Serializer& Serializer::operator=( const Serializer& before )
{
	std::cout << "Copy Serializer Assigment operator called" << std::endl;
	return (*this);
}

/**
 * @brief Copy constructor for Serializer.
 *
 * @param before The Serializer instance to copy.
 */
Serializer::Serializer( const Serializer& before )
{
	std::cout << "Copy Serializer Constructor called" << std::endl;
}

/**
 * @brief Destructor for Serializer.
 */
Serializer::~Serializer()
{
	std::cout << "Default Serializer Constructor called" << std::endl;
}
 

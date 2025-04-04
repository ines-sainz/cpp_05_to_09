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

Data* Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data*>(raw));
}
uintptr_t Serializer::serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Serializer& Serializer::operator=( const Serializer& before )
{
	std::cout << "Copy Serializer Assigment operator called" << std::endl;
	return (*this);
}

Serializer::Serializer( const Serializer& before )
{
	std::cout << "Copy Serializer Constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Default Serializer Constructor called" << std::endl;
}
 
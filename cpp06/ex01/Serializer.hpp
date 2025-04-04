/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:50:36 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 09:50:38 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	char	o;
}		Data;


class Serializer
{
	private:
		Serializer( void );

	public:
		static Data*		deserialize( uintptr_t raw );
		static uintptr_t	serialize( Data* ptr );
		Serializer& operator=( const Serializer& before );
		Serializer( const Serializer& before );
		~Serializer();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:49:11 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 09:49:13 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data	*data = new Data;
	uintptr_t	raw = 13;

	data->o = 'o';
	std::cout << "Data: " << data->o << std::endl;
	raw = Serializer::serialize(data);
	std::cout << "Serialized Data-> in Raw " << raw << std::endl;
	data = Serializer::deserialize(raw);
	std::cout << "Deserialized Raw-> in Data " << data->o << std::endl;

	std::cout << "\nRaw: " << raw << std::endl;
	data = Serializer::deserialize(raw);
	std::cout << "Deserialized Raw-> in Data " << data->o << std::endl;
	raw = Serializer::serialize(data);
	std::cout << "Serialized Raw-> in Data " << raw << std::endl;
}

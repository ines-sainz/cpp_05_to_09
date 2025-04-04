/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:01 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/10 15:42:03 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T* array;
		int len;

	public:
		class indexOutOfBounds: public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Index Out Of Bounds");
				}
		};
		T& operator[](int index);
		int	size() const;
		Array& operator=( const Array& before );
		Array( const Array& before );
		Array(unsigned int n);
		Array();
		~Array();
};

#include "Array.tpp"

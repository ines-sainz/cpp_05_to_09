/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:42:01 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/10 15:42:03 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= len)
		throw (Array::indexOutOfBounds());
	return (this->array[index]);
}

template <typename T>
int	Array<T>::size() const
{
	int len = 0;

	if (!this->array)
		return (0);
	while (this->array[len])
		len++;
	return (len);
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T> &before )
{
	int i = 0;
	if (before.array)
	{
    	std::cout << "HOLA" << std::endl;
		this->array = new T[before.size()];
		while (before.array[i])
		{
			this->array[i] = before.array[i];
			i++;
		}
	}
	else
		this->array = NULL;
	this->len = before.len;
	return (*this);
}

template <typename T>
Array<T>::Array( const Array& before )
{
	*this = before;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->len = n;
}

template <typename T>
Array<T>::Array()
{
	this->array = NULL;
	len = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

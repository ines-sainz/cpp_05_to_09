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

/**
 * @brief Accesses the element at the given index with bounds checking.
 * 
 * @tparam T Type of elements in the array.
 * @param index Index to access.
 * @return T& Reference to the element at the specified index.
 * @throw indexOutOfBounds If the index is out of valid range.
 */
template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= len)
		throw (Array::indexOutOfBounds());
	return (this->array[index]);
}

/**
 * @brief Returns the number of elements in the array.
 * 
 * @tparam T Type of elements in the array.
 * @return int Number of elements.
 */
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

/**
 * @brief Assignment operator overload.
 * 
 * Copies the contents of another array into this one.
 * 
 * @tparam T Type of elements in the array.
 * @param before Reference to the array to copy from.
 * @return Array<T>& Reference to the assigned array.
 */
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

/**
 * @brief Copy constructor.
 * 
 * Creates a copy of another Array object.
 * 
 * @tparam T Type of elements in the array.
 * @param before The Array object to copy.
 */
template <typename T>
Array<T>::Array( const Array& before )
{
	*this = before;
}

/**
 * @brief Parameterized constructor.
 * 
 * Allocates memory for an array of size n.
 * 
 * @tparam T Type of elements in the array.
 * @param n Number of elements to allocate.
 */
template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->len = n;
}

/**
 * @brief Default constructor.
 * 
 * Initializes an empty array.
 * 
 * @tparam T Type of elements in the array.
 */
template <typename T>
Array<T>::Array()
{
	this->array = NULL;
	len = 0;
}

/**
 * @brief Destructor.
 * 
 * Frees allocated memory for the array.
 * 
 * @tparam T Type of elements in the array.
 */
template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:05:05 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/10 12:05:07 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/**
 * @brief Applies a function to each element of an array.
 * 
 * This function modifies the array in-place by applying the given function
 * to each element.
 * 
 * @tparam T Type of the elements in the array.
 * @param array Pointer to the array.
 * @param lenght Number of elements in the array.
 * @param function Function pointer to apply to each element.
 */
template <typename T>
void	iter(T *array, int lenght, T (*function)(T))
{
	for (int i = 0; i < lenght; i++)
	{
		array[i] = function(array[i]);
	}
	
}

/**
 * @brief Converts a lowercase character to uppercase.
 * 
 * Assumes input is a lowercase ASCII letter.
 * 
 * @param c Character to convert.
 * @return char Uppercase equivalent of the input character.
 */
char up(char c)
{
	return (c - 32);
}

/**
 * @brief Main function to demonstrate iter template function.
 * 
 * Applies character transformation to integer array and C-style string using
 * the iter template and prints the results before and after.
 * 
 * @return int Exit status code.
 */
int main()
{
	int	ii[] = {'a', 'd', 'g', 'c'};

	std::cout << "before: " << (char)ii[0] << " " << (char)ii[1] << " " << (char)ii[2] << " " << (char)ii[3] << std::endl;
	iter(ii, 4, toupper);
	std::cout << "after: " << (char)ii[0] << " " << (char)ii[1] << " " << (char)ii[2] << " " << (char)ii[3] << std::endl;

	char cc[] = "hola";
	std::cout << "before: " << cc << std::endl;
	iter(cc, 4, up);
	std::cout << "after: " << cc << std::endl;
}

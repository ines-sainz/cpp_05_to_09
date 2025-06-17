/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:47:27 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 18:47:30 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

/**
 * @brief Returns the minimum of two values.
 * 
 * @tparam T Type of the values to compare.
 * @param a First value.
 * @param b Second value.
 * @return T The smaller of the two values.
 */
template <typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief Returns the maximum of two values.
 * 
 * @tparam T Type of the values to compare.
 * @param a First value.
 * @param b Second value.
 * @return T The larger of the two values.
 */
template <typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * @brief Swaps the values of two variables.
 * 
 * @tparam T Type of the values to swap.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 */
template <typename T>
void	swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

/**
 * @brief Main function to demonstrate the use of swap, min, and max templates.
 * 
 * Tests the template functions with integers and strings, printing the
 * results to standard output.
 * 
 * @return int Exit status code.
 */
int main( void )
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}

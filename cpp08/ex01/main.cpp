/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:37:57 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/11 16:37:58 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Demonstrates usage of the Span class.
 * 
 * Creates a Span of size 5, adds numbers, and prints the shortest and 
 * longest spans. Then creates a large Span of size 10001, fills it with 
 * values from 1 to 10001, and prints its shortest and longest spans.
 * 
 * @return int Always returns 0.
 */
int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	

	Span newSpan = Span(10001);
	newSpan.fillSpan(1, 10001);
	std::cout << newSpan.shortestSpan() << std::endl;
	std::cout << newSpan.longestSpan() << std::endl;

	return (0);
}

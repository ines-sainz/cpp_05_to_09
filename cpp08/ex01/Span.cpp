/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:38:52 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/11 16:38:55 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Fills the internal vector with values ranging from min to max.
 * 
 * If min is greater than max, the values are swapped. The method fills 
 * the vector repeatedly with values from min to max until the vector size 
 * reaches the maximum allowed integers (maxInts).
 * 
 * @param min The minimum integer value.
 * @param max The maximum integer value.
 */
void Span::fillSpan( int min, int max )
{
	int	num;
	if (min > max)
	{
		num = min;
		min = max;
		max = num;
	}
	num = min;
	while (this->vector.size() < this->maxInts)
	{
		vector.push_back(num);
		if (num == max)
			num = min - 1;
		num++;
	}
}

/**
 * @brief Adds a single number to the vector if capacity allows.
 * 
 * Throws a maxIntsReached exception if the vector size has reached maxInts.
 * 
 * @param i The integer to add.
 * @throws Span::maxIntsReached If the vector is full.
 */
void Span::addNumber( int i )
{
	if (vector.size() >= this->maxInts)
		throw (Span::maxIntsReached());
	vector.push_back(i);
}

/**
 * @brief Calculates the longest span (max difference) between elements.
 * 
 * Sorts the vector and returns the difference between the largest and 
 * smallest elements. Throws noSpanFound if the vector is empty or has 
 * insufficient elements.
 * 
 * @return int The longest span.
 * @throws Span::noSpanFound If vector is empty or invalid.
 */
int	Span::longestSpan()
{
	int	span;

	if (this->vector.empty())
		throw (Span::noSpanFound());
	std::sort(this->vector.begin(), this->vector.end());
	
	if (this->vector.begin() == this->vector.end())
		throw (Span::noSpanFound());

	std::vector<int>::iterator first = this->vector.begin();
	std::vector<int>::iterator last = this->vector.begin();
	while (last + 1 != this->vector.end())
		last++;
	span = *last - *first;
	return (span);
}

/**
 * @brief Calculates the shortest span (minimum difference) between elements.
 * 
 * Sorts the vector and finds the smallest difference between any two adjacent 
 * elements. Throws noSpanFound if the vector is empty or invalid.
 * 
 * @return int The shortest span.
 * @throws Span::noSpanFound If vector is empty or invalid.
 */
int	Span::shortestSpan()
{
	int	span = 0;
	int	tempSpan;

	if (this->vector.empty())
		throw (Span::noSpanFound());
	std::sort(this->vector.begin(), this->vector.end());
	
	if (this->vector.begin() == this->vector.end())
		throw (Span::noSpanFound());

	std::vector<int>::iterator temp = this->vector.begin();
	std::vector<int>::iterator iter = this->vector.begin();
	if (temp + 1 == this->vector.end())
	{
		span = *(temp + 1) - *temp;
		return (span);
	}
	while (temp + 1 != this->vector.end())
	{
		temp++;
		tempSpan = *temp - *iter;
		if (iter == this->vector.begin() || tempSpan < span)
			span = tempSpan;
		iter++;
	}
	return (span);
}

/**
 * @brief Constructs a Span with a maximum number of integers allowed.
 * 
 * Initializes maxInts with the provided value and prints a constructor message.
 * 
 * @param n Maximum number of integers the Span can hold.
 */
Span::Span( unsigned int n )
{
	std::cout << "Span Constructor called" << std::endl;
	this->maxInts = n;
}

/**
 * @brief Destructor for Span.
 * 
 * Prints a destructor message.
 */
Span::~Span()
{
	std::cout << "Default Span Destructor called" << std::endl;
}

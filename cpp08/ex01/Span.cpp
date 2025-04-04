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

void Span::addNumber( int i )
{
	if (vector.size() >= this->maxInts)
		throw (Span::maxIntsReached());
	vector.push_back(i);
}

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

Span::Span( unsigned int n )
{
	std::cout << "Span Constructor called" << std::endl;
	this->maxInts = n;
}

Span::~Span()
{
	std::cout << "Default Span Destructor called" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:00:34 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/05 16:00:36 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter( void ){};

	public:
		static void convert( std::string toConvert );
		ScalarConverter& operator=( const ScalarConverter& before );
		ScalarConverter( const ScalarConverter& before );
		~ScalarConverter();
};

void	handleWeird( std::string toConvert, int i );
int		isWeird( std::string toConvert );
int		isFloat( std::string toConvert );
int		isDouble( std::string toConvert );
int		isInt( std::string toConvert );
void	isChar( std::string toConvert );
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:00:28 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/05 16:00:29 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	handleWeird( std::string toConvert, int i )
{
	std::cout << "char: impossible\nint: impossible" << std::endl;
	if (i == 1)
	{
		std::cout << "float: " << toConvert << std::endl;
		std::cout << "double: ";
		for (size_t i = 0; i < toConvert.length() - 1; i++)
			std::cout << toConvert[i];
		std::cout << "\n";
	}
	else
	{
		std::cout << "float: " << toConvert << "f" << std::endl;
		std::cout << "double: " << toConvert << std::endl;
	}
}

int isWeird( std::string toConvert )
{
 	if (toConvert == "nanf" || toConvert == "+inff" || toConvert == "-inff")
	{
		handleWeird(toConvert, 1);
		return (1);
	}
	if (toConvert == "nan" || toConvert == "+inf" || toConvert == "-inf")
	{
		handleWeird(toConvert, 0);
		return (1);
	}
	return (0);
};

int isFloat( std::string toConvert )
{
	char	*end;
	int 	dot = 0;
	for (size_t i = 0; i < toConvert.length() - 1; i++)
	{
		if (toConvert[i] == '.')
			dot++;
		if ((isdigit(toConvert[i]) == 0 && toConvert[i] != '.' && toConvert[i] != '-' && toConvert[i] != '+')
			|| (toConvert[i] == '.' && dot == 2))
		{
			return (0);
		}
	}
	if (toConvert[toConvert.length() - 1] != 'f')
		return (0);
	double	doubleint = strtod(toConvert.c_str(), &end);
	int		intToConvert = static_cast<int>(doubleint);
	if (intToConvert < 32 || intToConvert > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char	charint = static_cast<char>(intToConvert);
		std::cout << "char: '" << charint << "'" << std::endl;
	}
	std::cout << "int: " << intToConvert << std::endl;
	std::cout << "float: "  << std::fixed << std::setprecision(1) << doubleint << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleint << std::endl;
	return (1);
}

int isDouble( std::string toConvert )
{
	char	*end;
	int 	dot = 0;
	for (size_t i = 0; i < toConvert.length(); i++)
	{
		if (toConvert[i] == '.')
			dot++;
		if ((isdigit(toConvert[i]) == 0 && toConvert[i] != '.' && toConvert[i] != '-' && toConvert[i] != '+')
			|| (toConvert[i] == '.' && dot == 2))
		{
			return (0);
		}
	}
	double	doubleint = strtod(toConvert.c_str(), &end);
	int		intToConvert = static_cast<int>(doubleint);
	if (intToConvert < 32 || intToConvert > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char	charint = static_cast<char>(intToConvert);
		std::cout << "char: '" << charint << "'" << std::endl;
	}
	std::cout << "int: " << intToConvert << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << doubleint << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleint << std::endl;
	return (1);
}

int	isInt( std::string toConvert )
{
	char	*end;
	for (size_t i = 0; i < toConvert.length(); i++)
	{
		if (isdigit(toConvert[i]) == 0 && toConvert[i] != '-' && toConvert[i] != '+')
			return (0);
	}
	double	doubleint = strtod(toConvert.c_str(), &end);
	int		intToConvert = static_cast<int>(doubleint);
	if (intToConvert < 32 || intToConvert > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char	charint = static_cast<char>(intToConvert);
		std::cout << "char: '" << charint << "'" << std::endl;
	}
	std::cout << "int: " << intToConvert << std::endl;
	std::cout << "float: " << doubleint << ".0f" << std::endl;
	std::cout << "double: " << doubleint << ".0" << std::endl;
	return (1);
}

void	isChar( std::string toConvert )
{
	char	charToConvert = toConvert[0];
	std::cout << "char: '" << toConvert << "'" << std::endl;
	int intchar = charToConvert;
	double doublechar = static_cast<double>(intchar);
	std::cout << "int: " << intchar << std::endl;
	std::cout << "float: " << doublechar << ".0f" << std::endl;
	std::cout << "double: " << doublechar << ".0" << std::endl;
}

void ScalarConverter::convert( std::string toConvert )
{
	if (toConvert.length() == 1 && isdigit(toConvert[0]) == 0)
		isChar(toConvert);
	else if (isWeird(toConvert))
		return ;
	else if (isInt(toConvert))
		return ;
	else if (isDouble(toConvert))
		return ;
	else if (isFloat(toConvert))
		return ;
		
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& before )
{
	std::cout << "Copy ScalarConverter Assigment Operator called" << std::endl;
	(void)before;
	return (*this);
}

ScalarConverter::ScalarConverter( const ScalarConverter& before )
{
	std::cout << "Copy ScalarConverter Contructor called" << std::endl;
	*this = before;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Default ScalarConverter Destructor called" << std::endl;
}

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

/**
 * @brief Handle special float/double string cases (nan, inf).
 *
 * @param toConvert The string to be interpreted.
 * @param i Mode selector: 1 = float style, 0 = double style.
 */
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

/**
 * @brief Check if the string represents a special float/double value.
 *
 * @param toConvert The input string.
 * @return 1 if it is a special value, 0 otherwise.
 */
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
}

/**
 * @brief Check if the string represents a float value.
 *
 * Converts the string to float, then prints its char, int, float and double
 * representations.
 *
 * @param toConvert The input string.
 * @return 1 if valid float, 0 otherwise.
 */
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

/**
 * @brief Check if the string represents a double value.
 *
 * Converts the string to double, then prints its char, int, float and double
 * representations.
 *
 * @param toConvert The input string.
 * @return 1 if valid double, 0 otherwise.
 */
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

/**
 * @brief Check if the string represents an integer value.
 *
 * Converts the string to integer, then prints its char, int, float and double
 * representations.
 *
 * @param toConvert The input string.
 * @return 1 if valid int, 0 otherwise.
 */
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

/**
 * @brief Handle single character conversion.
 *
 * Interprets the character as char, int, float, and double, then prints each.
 *
 * @param toConvert The single-character string.
 */
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

/**
 * @brief Convert string input to all scalar types (char, int, float, double).
 *
 * Dispatches to the appropriate converter based on the string contents.
 *
 * @param toConvert The string to convert.
 */
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

/**
 * @brief Assignment operator for ScalarConverter.
 *
 * @param before The object to assign from.
 * @return Reference to this object.
 */
ScalarConverter& ScalarConverter::operator=( const ScalarConverter& before )
{
	std::cout << "Copy ScalarConverter Assigment Operator called" << std::endl;
	(void)before;
	return (*this);
}

/**
 * @brief Copy constructor for ScalarConverter.
 *
 * @param before The object to copy from.
 */
ScalarConverter::ScalarConverter( const ScalarConverter& before )
{
	std::cout << "Copy ScalarConverter Contructor called" << std::endl;
	*this = before;
}

/**
 * @brief Destructor for ScalarConverter.
 */
ScalarConverter::~ScalarConverter()
{
	std::cout << "Default ScalarConverter Destructor called" << std::endl;
}

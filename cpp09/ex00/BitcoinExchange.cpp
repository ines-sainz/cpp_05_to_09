/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:13:49 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:13:51 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Validates and parses a date string key in "YYYY-MM-DD" format.
 * 
 * Checks if the input string follows the date format, validates year,
 * month, day values including leap years. Returns an integer encoding
 * of the date or -1 if invalid.
 * 
 * @param key Date string to validate.
 * @return int Encoded integer key for valid date or -1 on error.
 */
int	check_set_key(std::string key)
{
	int	int_key = 0;
	int	i = 0;
	int	is_lap_year = 0;
	int	month = 0;
	int	day = 0;

	while (key[i] && i < 4)
	{
		if (!(key[i] >= '0' && key[i] <= '9'))
			return (-1);
		int_key = int_key * 10 + (key[i] - '0');
		i++;
	}
	if (i != 4 || int_key <= 0 || key[i] != '-')
		return (-1);
	if ((int_key % 4 == 0 && int_key % 100 != 0) || int_key % 400 == 0)
		is_lap_year = 1;
	i++;
	while (key[i] && i < 7)
	{
		int_key = int_key * 10 + (key[i] - '0');
		month = month * 10 + (key[i] - '0');
		i++;
	}
	if (i != 7 || key[i] != '-' || month <= 0 || month > 12)
		return (-1);
	i++;
	while (key[i] && i < 10)
	{
		int_key = int_key * 10 + (key[i] - '0');
		day = day * 10 + (key[i] - '0');
		i++;
	}
	if (key[i] || i != 10 || day <= 0 || day > 31 || (month % 2 == 0 && day == 31) || (month == 2 && (day >= 30 || (is_lap_year == 0 && day == 29))))
		return (-1);
	return (int_key);
}

/**
 * @brief Reads and validates input file lines against the CSV data map.
 * 
 * For each line in the input file, extracts a date key and a value,
 * validates them, finds corresponding CSV value or nearest previous key,
 * computes and prints the product of CSV value and input value.
 * Prints errors for invalid inputs.
 * 
 * @param fileTxt Pointer to input file stream to read.
 * @param csv_map Map containing date keys and their corresponding values.
 * @return int Always returns 0.
 */
int	check_input_file(std::ifstream *fileTxt, std::map<int, double>& csv_map)
{
	std::string	key;
	std::string	value;
	int			separator;
	std::string	lines;
	double		double_value;
	int			int_key;
	double		csv_value = 0;
	std::map<int, double>::iterator it = csv_map.begin();

	std::getline(*fileTxt, lines);
	while (std::getline(*fileTxt, lines))
	{
		separator = lines.find(" | ");
		if (separator < 0)
		{
			std::cout << "Error: bad input => " << lines << std::endl;
			continue ;
		}
		key = lines.substr(0, separator);
		int_key = check_set_key(key);
		if (int_key == -1)
		{
			std::cout << "Error: bad input => " << key << std::endl;
			continue ;
		}
		value = lines.substr(separator + 3);
		if (value.length() > 10)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		double_value = atof(value.c_str());
		if (double_value < 0 || double_value > INT_MAX)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (int_key < it->first)
			csv_value = it->second * double_value;
		else
		{
			it = csv_map.find(int_key);
			if (it == csv_map.end())
			{
				while (it->first > 0 && it == csv_map.end())
				{
					int_key--;
					it = csv_map.find(int_key);
				}
				csv_value = it->second * double_value;
			}
			else
			{
				csv_value = it->second * double_value;
			}
		}
		std::cout << key << " => " << value << " = " << csv_value << std::endl;
	}
	return (0);
}

/**
 * @brief Reads a CSV file and populates a map with integer keys and double values.
 * 
 * Parses lines of the CSV file, extracting integer date keys and corresponding
 * double values. Stores them in the provided map.
 * 
 * @param csv_map Map to fill with keys and values from the CSV.
 * @param fileCsv Pointer to the CSV file stream.
 * @return int Returns 0 on success, 1 if CSV lines are malformed.
 */
int	set_csv_file(std::map<int, double>& csv_map, std::ifstream *fileCsv)
{
	std::string	key;
	std::string	value;
	int			comma_pos;
	std::string	lines;
	int			int_key = 0;
	double		double_value;
	int			i = 0;

	std::getline(*fileCsv, lines);
	while (std::getline(*fileCsv, lines))
	{
		i = 0;
		int_key = 0;
		comma_pos = lines.find(',');
		if (comma_pos < 0)
			return (1);

		key = lines.substr(0, comma_pos);
		while (key[i])
		{
			if (key[i] >= '0' && key[i] <= '9')
			{
				int_key = int_key * 10 + (key[i] - '0');
			}
			i++;
		}
		value = lines.substr(comma_pos + 1);
		double_value = atof(value.c_str());
		csv_map[int_key] = double_value;
	}
	return (0);
}

/**
 * @brief Main controller function that processes Bitcoin exchange data.
 * 
 * Opens input and CSV data files, reads CSV data into a map, then checks
 * the input file lines against the CSV data, printing results or errors.
 * 
 * @param argv Command line arguments; argv[1] should be the input file path.
 * @return int Returns 0 on success, 1 on file opening or parsing failure.
 */
int	BitcoinExchange(char **argv)
{
	std::ifstream	fileTxt;
	std::ifstream	fileCsv;
	std::map<int, double> csv_map;

	fileTxt.open(argv[1], std::ios::in);
	if (!fileTxt.is_open())
	{
		std::cout << "Can't open txt file" << std::endl;
		return (1);
	}
	fileCsv.open("data.csv", std::ios::in);
	if (!fileCsv.is_open())
	{
		fileTxt.close();
		std::cout << "Can't open csv file" << std::endl;
		return (1);
	}
	if (set_csv_file(csv_map, &fileCsv) == 1)
	{
		fileCsv.close();
		fileTxt.close();
		return (1);
	}
	if (check_input_file(&fileTxt, csv_map) == 1)
	{
		fileCsv.close();
		fileTxt.close();
		return (1);
	}
	return (0);
}

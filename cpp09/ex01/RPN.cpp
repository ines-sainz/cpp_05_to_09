/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:15:06 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:08 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @brief Evaluates a Reverse Polish Notation (RPN) expression from a string.
 * 
 * Parses the input string character by character, pushing numbers onto a stack
 * and applying operations (+, -, *, /) to the top two numbers when encountered.
 * Detects invalid input such as multiple digits without separator or insufficient
 * operands for an operator. Prints the final result or "Error" for invalid input.
 * 
 * @param argv Input string containing the RPN expression.
 * @return int Returns 0 on successful evaluation, 1 on error.
 */
int	reverse_polish_notation(char *argv)
{
	std::stack<int>	num_stack;
	int				i = 0;
	int				total;
	int				num1;
	int				num2;

	while (argv[i])
	{
		if (isdigit(argv[i]) && isdigit(argv[i + 1]))
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		if (isdigit(argv[i]))
			num_stack.push(argv[i] - '0');
		else if ((argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/') && num_stack.size() >= 2)
		{
			num1 = num_stack.top();
			num_stack.pop();
			num2 = num_stack.top();
			num_stack.pop();
			if (argv[i] == '+')
				total = num2 + num1;
			if (argv[i] == '-')
				total = num2 - num1;
			if (argv[i] == '*')
				total = num2 * num1;
			if (argv[i] == '/')
				total = num2 / num1;
			num_stack.push(total);
		}
		else if (argv[i] == ' ')
		{
			i++;
			continue ;
		}
		else
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		i++;
	}
	if (num_stack.size() > 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::cout << num_stack.top() << std::endl;
	return (0);
}

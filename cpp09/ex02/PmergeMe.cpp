/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:16:01 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:16:03 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Parses command line arguments into a vector of unique integers.
 *
 * Checks that each argument is a positive integer string with up to 10
 * digits, no duplicates allowed. Returns 1 on invalid input or duplicates,
 * 0 on success.
 *
 * @param argv Array of argument strings.
 * @param vector Pointer to vector<int> to fill with parsed numbers.
 * @return int 0 if success, 1 on error.
 */
int	parse_vector(char **argv, std::vector<int> *vector)
{
	std::vector<int>::iterator	it = vector->begin();
	int							i = 1;
	int							j = 0;
	long						num;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		if (j > 10)
			return (1);
		num = atol(argv[i]);
		if (num > INT_MAX)
			return (1);
		it = vector->begin();
		while (it != vector->end())
		{
			if (*it == num)
				return (1);
			it++;
		}
		vector->push_back(num);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if a vector is sorted in ascending order.
 *
 * @param vector Pointer to vector<int> to check.
 * @return int Returns 0 if ordered ascending, 1 if not.
 */
int	ordered_vector(std::vector<int> *vector)
{
	std::vector<int>::iterator	it = vector->begin();
	std::vector<int>::iterator	it2 = vector->begin();

	it2++;
	while (it2 != vector->end())
	{
		if (*it > *it2)
			return (1);
		it++;
		it2++;
	}
	return (0);
}

/**
 * @brief Splits input vector into two vectors of pairs, sorts the smaller
 *        pair vector in ascending order using bubble sort.
 *
 * Even indices go to ordered_small_pair_vector; odd indices to big_pair_vector.
 *
 * @param vector Pointer to input vector<int>.
 * @param ordered_small_pair_vector Pointer to vector<int> to fill with smaller
 *        elements of pairs.
 * @param big_pair_vector Pointer to vector<int> to fill with bigger elements
 *        of pairs.
 */
void	second_vector_step(std::vector<int> *vector, std::vector<int> *ordered_small_pair_vector, std::vector<int> *big_pair_vector)
{
	std::vector<int>::iterator	it = vector->begin();
	int							i = 0;
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;
	int							temp;

	while (it != vector->end())
	{
		if (i % 2 == 0)
			ordered_small_pair_vector->push_back(*it);
		else
			big_pair_vector->push_back(*it);
		i++;
		it++;
	}
	it1 = ordered_small_pair_vector->begin();
	it2 = ordered_small_pair_vector->begin();
	it2++;
	while (ordered_vector(ordered_small_pair_vector) != 0)
	{
		if (it2 == ordered_small_pair_vector->end())
		{
			it1 = ordered_small_pair_vector->begin();
			it2 = ordered_small_pair_vector->begin();
			it2++;
			continue ;
		}
		if (*it1 > *it2)
		{
			temp = *it1;
			*it1 = *it2;
			*it2 = temp;
		}
		it1++;
		it2++;
	}
}

/**
 * @brief Sorts each pair in the input vector so that the smaller element is
 *        first and the larger second.
 *
 * Iterates pairs by stepping through the vector by 2.
 *
 * @param vector Pointer to vector<int> to sort pairs in place.
 */
void	first_vector_step(std::vector<int> *vector)
{
	std::vector<int>::iterator	it1 = vector->begin();
	std::vector<int>::iterator	it2 = vector->begin();
	int							temp;
	int							i = 0;

	it2++;
	while (it2 != vector->end())
	{
		if (i % 2 == 0)
		{
			if (*it1 >= *it2)
			{
				temp = *it1;
				*it1 = *it2;
				*it2 = temp;
			}
		}
		i++;
		it1++;
		it2++;
	}
}

/**
 * @brief Parses command line arguments into a vector, sorts pairs, splits
 *        and merges pairs into a sorted vector.
 *
 * Inserts elements from big pairs into ordered_small_pair_vector maintaining
 * order.
 *
 * @param argv Argument strings.
 * @param vector Pointer to vector<int> to fill.
 * @param ordered_small_pair_vector Pointer to vector<int> to fill with final
 *        sorted result.
 * @return int Returns 0 on success, 1 on error.
 */
int	order_with_vector(char **argv, std::vector<int> *vector, std::vector<int> *ordered_small_pair_vector)
{
	if (parse_vector(argv, vector) == 1)
		return (1);
	first_vector_step(vector);
	std::vector<int>	big_pair_vector;
	second_vector_step(vector, ordered_small_pair_vector, &big_pair_vector);

	std::vector<int>::iterator	it_big = big_pair_vector.begin();
	std::vector<int>::iterator	it_small = ordered_small_pair_vector->begin();
	while (it_big != big_pair_vector.end())
	{
		it_small = ordered_small_pair_vector->begin();
		while (it_small != ordered_small_pair_vector->end())
		{
			if (*it_big < *it_small)
			{
				ordered_small_pair_vector->insert(it_small, *it_big);
				break ;
			}
			it_small++;
		}
		it_big++;
	}
	return (0);
}






/**
 * @brief Parses command line arguments into a list of unique integers.
 *
 * Checks each argument is a digit string <= 10 chars and no duplicates.
 *
 * @param argv Argument strings.
 * @param list Pointer to list<int> to fill.
 * @return int Returns 0 on success, 1 on error.
 */
int	parse_list(char **argv, std::list<int> *list)
{
	std::list<int>::iterator	it = list->begin();
	int							i = 1;
	int							j = 0;
	long						num;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		if (j > 10)
			return (1);
		num = atol(argv[i]);
		if (num > INT_MAX)
			return (1);
		it = list->begin();
		while (it != list->end())
		{
			if (*it == num)
				return (1);
			it++;
		}
		list->push_back(num);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if a list is sorted in ascending order.
 *
 * @param list Pointer to list<int> to check.
 * @return int Returns 0 if ordered ascending, 1 if not.
 */
int	ordered_list(std::list<int> *list)
{
	std::list<int>::iterator	it = list->begin();
	std::list<int>::iterator	it2 = list->begin();

	it2++;
	while (it2 != list->end())
	{
		if (*it > *it2)
			return (1);
		it++;
		it2++;
	}
	return (0);
}

/**
 * @brief Splits list into two lists of pairs and sorts the smaller pair list.
 *
 * Even-indexed elements go to ordered_small_pair_list; odd-indexed to
 * big_pair_list. Sorts ordered_small_pair_list ascending with bubble sort.
 *
 * @param list Pointer to input list<int>.
 * @param ordered_small_pair_list Pointer to list<int> to fill with smaller pair
 *        elements.
 * @param big_pair_list Pointer to list<int> to fill with bigger pair elements.
 */
void	second_list_step(std::list<int> *list, std::list<int> *ordered_small_pair_list, std::list<int> *big_pair_list)
{
	std::list<int>::iterator	it = list->begin();
	int							i = 0;
	std::list<int>::iterator	it1;
	std::list<int>::iterator	it2;
	int							temp;

	while (it != list->end())
	{
		if (i % 2 == 0)
			ordered_small_pair_list->push_back(*it);
		else
			big_pair_list->push_back(*it);
		i++;
		it++;
	}
	it1 = ordered_small_pair_list->begin();
	it2 = ordered_small_pair_list->begin();
	it2++;
	while (ordered_list(ordered_small_pair_list) != 0)
	{
		if (it2 == ordered_small_pair_list->end())
		{
			it1 = ordered_small_pair_list->begin();
			it2 = ordered_small_pair_list->begin();
			it2++;
			continue ;
		}
		if (*it1 > *it2)
		{
			temp = *it1;
			*it1 = *it2;
			*it2 = temp;
		}
		it1++;
		it2++;
	}
}

/**
 * @brief Sorts pairs in the list so smaller element is first in each pair.
 *
 * Iterates through the list stepping by 2 elements and swaps if needed.
 *
 * @param list Pointer to list<int> to sort pairs in place.
 */
void	first_list_step(std::list<int> *list)
{
	std::list<int>::iterator	it1 = list->begin();
	std::list<int>::iterator	it2 = list->begin();
	int							temp;
	int							i = 0;

	it2++;
	while (it2 != list->end())
	{
		if (i % 2 == 0)
		{
			if (*it1 >= *it2)
			{
				temp = *it1;
				*it1 = *it2;
				*it2 = temp;
			}
		}
		i++;
		it1++;
		it2++;
	}
}

/**
 * @brief Orders the elements in a list using a two-step pair sorting method.
 * 
 * First, performs the initial ordering on the input list. Then splits the list
 * into two separate lists: one for smaller elements in pairs, and another for
 * bigger elements. Finally merges the big pair list into the ordered smaller
 * pair list in sorted order.
 * 
 * @param list Pointer to the input std::list<int> to be ordered.
 * @param ordered_small_pair_list Pointer to the output std::list<int> that will
 *                                hold the ordered smaller pairs after sorting.
 * @return int Returns 0 on success.
 */
int	order_with_list(std::list<int> *list, std::list<int> *ordered_small_pair_list)
{
	first_list_step(list);
	std::list<int> big_pair_list;
	second_list_step(list, ordered_small_pair_list, &big_pair_list);

	std::list<int>::iterator	it_big = big_pair_list.begin();
	std::list<int>::iterator	it_small = ordered_small_pair_list->begin();
	while (it_big != big_pair_list.end())
	{
		it_small = ordered_small_pair_list->begin();
		while (it_small != ordered_small_pair_list->end())
		{
			if (*it_big < *it_small)
			{
				ordered_small_pair_list->insert(it_small, *it_big);
				break ;
			}
			it_small++;
		}
		it_big++;
	}
	return (0);
}





/**
 * @brief Main function to parse, order, and compare std::list and std::vector
 *        sorting performance using PmergeMe algorithm.
 * 
 * Parses the command-line arguments into a std::list and orders it using the
 * pair-based sorting approach. Measures and prints the time taken for sorting
 * with std::list and std::vector containers. Also prints the list before and
 * after sorting.
 * 
 * @param argv Null-terminated array of C-string arguments representing input
 *             integers to be parsed and sorted.
 * @return int Returns 0 on success, 1 on error (e.g., invalid input).
 */
int	pmerge_me(char **argv)
{
	std::list<int>		list;
	std::list<int>		list_ordered;
	clock_t	time_list = clock();

	if (parse_list(argv, &list) == 1)
		return (1);
	std::list<int>		temp = list;
	if (order_with_list(&list, &list_ordered) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	double	end_list = static_cast<double>(clock() - time_list) / CLOCKS_PER_SEC * 1000;

	std::vector<int>	vector;
	std::vector<int>	vector_ordered;
	clock_t	time_vector = clock();
	
	if (order_with_vector(argv, &vector, &vector_ordered) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	double	end_vector = static_cast<double>(clock() - time_vector) / CLOCKS_PER_SEC * 1000;

	std::cout << "Before: ";
	std::list<int>::iterator	it = temp.begin();
	while (it != temp.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "After: ";
	it = list_ordered.begin();
	while (it != list_ordered.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << end_list << std::endl;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << end_vector << std::endl;

	return (0);
}

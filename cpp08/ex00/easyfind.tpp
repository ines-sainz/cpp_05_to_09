/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:28:56 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/11 10:28:58 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/**
 * @brief Searches for an integer value inside a container.
 * 
 * This template function takes a container and an integer to find.
 * It uses std::find to locate the integer in the container.
 * 
 * @tparam T Container type with const_iterator and begin/end methods.
 * @param a Container instance to search within.
 * @param i Integer value to search for.
 * @return int Returns 0 if found, -1 if not found.
 */
template <typename T>
int easyfind(T a, int i)
{
	typename T::const_iterator iterator = std::find(a.begin(), a.end(), i);
	if (iterator == a.end())
		return (-1);
	return (0);
}

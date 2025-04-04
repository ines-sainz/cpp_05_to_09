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

template <typename T>
int easyfind(T a, int i)
{
	typename T::const_iterator iterator = std::find(a.begin(), a.end(), i);
	if (iterator == a.end())
		return (-1);
	return (0);
}

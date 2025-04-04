/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:52:19 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 12:52:21 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
		Base	*base = NULL;
		base = base->generate();

		std::cout << "\n";
		base->identify(base);
		std::cout << "\n";
		base->identify(*base);
		std::cout << "\n";
		delete base;
}

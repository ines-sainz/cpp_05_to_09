/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:45:32 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 12:45:34 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
	private:
		/* data */

	public:
		void identify(Base& p);
		void identify(Base* p);
		Base* generate( void );
		Base( void );
		virtual ~Base();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:44:06 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/05 12:44:08 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class Intern
{
	private:
		/* data */
	public:
		AForm*	makeForm( std::string formName, std::string formTarget );
		Intern& operator=( const Intern& before );
		Intern( const Intern& before );
		Intern( void );
		~Intern();
};

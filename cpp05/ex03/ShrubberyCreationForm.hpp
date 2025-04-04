/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:41:37 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:39 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;

	public:
		virtual void execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& before);
		ShrubberyCreationForm( const ShrubberyCreationForm& before );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( void );
		~ShrubberyCreationForm();
};

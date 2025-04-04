/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:41:23 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:24 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

	public:
		virtual void execute(Bureaucrat const & executor) const;
		RobotomyRequestForm& operator=( const RobotomyRequestForm& before );
		RobotomyRequestForm( const RobotomyRequestForm& before );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( void );
		~RobotomyRequestForm();
};

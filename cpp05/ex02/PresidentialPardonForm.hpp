/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:41:08 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:09 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;

	public:
		virtual void execute(Bureaucrat const & executor) const;
		PresidentialPardonForm& operator=( const PresidentialPardonForm& before);
		PresidentialPardonForm( const PresidentialPardonForm& before );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( void );
		~PresidentialPardonForm();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:31:19 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:40:35 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		void 				execute( AForm& form ) const;
		void 				signForm( AForm& form ) const;
		void				incrementGrade();
		void				decrementGrade();
		int					getGrade() const;
		const std::string	getName() const;
		Bureaucrat&	operator=( const Bureaucrat& before);
		Bureaucrat( const Bureaucrat& before );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( void );
		~Bureaucrat();
};

std::ostream&	operator<<( std::ostream &out, Bureaucrat const &classToPrint );

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:30:16 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:40:09 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
///#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

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
		
		virtual void execute(Bureaucrat const & executor) const = 0;
		void				beSigned( Bureaucrat bureaucrat );
		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;

		AForm& operator=( const AForm& before );
		AForm( const AForm& before );
		AForm( std::string name, int gradeToSign, int gradeToExecute );
		AForm();
		~AForm();
};

std::ostream&	operator<<( std::ostream &out, AForm const &classToPrint );

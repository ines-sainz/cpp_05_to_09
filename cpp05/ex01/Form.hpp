/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:30:16 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/17 11:30:18 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
///#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class Form
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
		
		void				beSigned( Bureaucrat bureaucrat );
		const std::string	getName() const;
		bool				getIsSigned() const;
		const int			getGradeToSign() const;
		const int			getGradeToExecute() const;

		Form& operator=( const Form& before );
		Form( const Form& before );
		Form( std::string name, int gradeToSign, int gradeToExecute );
		Form();
		~Form();
};

std::ostream&	operator<<( std::ostream &out, Form const &classToPrint );

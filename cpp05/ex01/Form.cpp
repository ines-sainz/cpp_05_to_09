/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:39 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/17 11:29:40 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

void Form::beSigned( Bureaucrat bureaucrat )
{
	if ( this->gradeToSign < bureaucrat.getGrade())
		throw (Form::GradeTooLowException());
	this->isSigned = 1;
}

const std::string	Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

const int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

const int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

Form& Form::operator=( const Form& before )
{
	std::cout << "Copy Form Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.name;
	const_cast<int&>(this->gradeToExecute) = before.getGradeToExecute();
	const_cast<int&>(this->gradeToSign) = before.getGradeToSign();
	this->isSigned = before.isSigned;
	return (*this);
}

Form::Form( const Form& before ) : name(before.name), gradeToSign(before.gradeToSign), gradeToExecute(before.gradeToExecute)
{
	this->isSigned = before.isSigned;
	std::cout << "Copy Bureaucrat Constructor called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (Form::GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (Form::GradeTooLowException());
	*this = before;
}

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Form " << name << " Constructor called" << std::endl;
	this->isSigned = 0;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (Form::GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (Form::GradeTooLowException());
}

Form::Form() : name(""), gradeToExecute(150), gradeToSign(150)
{
	this->isSigned = 0;
	std::cout << "Default Form Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Default Form Destructor called" << std::endl;
}

std::ostream&	operator<<( std::ostream &out, Form const &classToPrint )
{
	out << classToPrint.getName() << ", Form grade to sign: " << classToPrint.getGradeToSign() << " grade to execute: " << classToPrint.getGradeToExecute() << std::endl;
	return (out);
}

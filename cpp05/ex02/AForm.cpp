/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:39 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:39:46 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

void AForm::beSigned( Bureaucrat bureaucrat )
{
	if ( this->gradeToSign < bureaucrat.getGrade())
		throw (AForm::GradeTooLowException());
	this->isSigned = 1;
}

const std::string	AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

const int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

const int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

AForm& AForm::operator=( const AForm& before )
{
	std::cout << "Copy AForm Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.name;
	const_cast<int&>(this->gradeToExecute) = before.getGradeToExecute();
	const_cast<int&>(this->gradeToSign) = before.getGradeToSign();
	this->isSigned = before.isSigned;
	return (*this);
}

AForm::AForm( const AForm& before ) : name(before.name), gradeToSign(before.gradeToSign), gradeToExecute(before.gradeToExecute)
{
	this->isSigned = before.isSigned;
	std::cout << "Copy Bureaucrat Constructor called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (AForm::GradeTooLowException());
	*this = before;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "AForm " << name << " Constructor called" << std::endl;
	this->isSigned = 0;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm() : name(""), gradeToExecute(150), gradeToSign(150)
{
	this->isSigned = 0;
	std::cout << "Default AForm Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Default AForm Destructor called" << std::endl;
}

std::ostream&	operator<<( std::ostream &out, AForm const &classToPrint )
{
	out << classToPrint.getName() << ", AForm grade to sign: " << classToPrint.getGradeToSign() << " grade to execute: " << classToPrint.getGradeToExecute() << std::endl;
	return (out);
}

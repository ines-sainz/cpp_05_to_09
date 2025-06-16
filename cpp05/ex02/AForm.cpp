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

/**
 * @brief Exception message for grade too low error.
 * 
 * @return const char* Fixed message "Grade is too low".
 */
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief Exception message for grade too high error.
 * 
 * @return const char* Fixed message "Grade is too high".
 */
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * @brief Sign the form if the bureaucrat has sufficient grade.
 * 
 * @param bureaucrat Bureaucrat attempting to sign the form.
 * @throws GradeTooLowException if bureaucrat's grade is too low.
 */
void AForm::beSigned( Bureaucrat bureaucrat )
{
	if ( this->gradeToSign < bureaucrat.getGrade())
		throw (AForm::GradeTooLowException());
	this->isSigned = 1;
}

/**
 * @brief Get the name of the form.
 * 
 * @return std::string Form's name.
 */
const std::string	AForm::getName() const
{
	return (this->name);
}

/**
 * @brief Check if the form is signed.
 * 
 * @return bool True if signed, false otherwise.
 */
bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

/**
 * @brief Get the grade required to sign the form.
 * 
 * @return int Required grade to sign.
 */
const int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

/**
 * @brief Get the grade required to execute the form.
 * 
 * @return int Required grade to execute.
 */
const int AForm::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

/**
 * @brief Assignment operator overload for AForm.
 * 
 * Copies the contents of another AForm into this one.
 * 
 * @param before Source AForm to copy from.
 * @return AForm& Reference to this AForm.
 */
AForm& AForm::operator=( const AForm& before )
{
	std::cout << "Copy AForm Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.name;
	const_cast<int&>(this->gradeToExecute) = before.getGradeToExecute();
	const_cast<int&>(this->gradeToSign) = before.getGradeToSign();
	this->isSigned = before.isSigned;
	return (*this);
}

/**
 * @brief Copy constructor for AForm.
 * 
 * Copies all attributes from another AForm, with grade validation.
 * 
 * @param before AForm object to copy.
 */
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

/**
 * @brief Parameterized constructor for AForm.
 * 
 * Initializes name, grades, and sets form unsigned. Validates grades.
 * 
 * @param name Name of the form.
 * @param gradeToSign Grade required to sign.
 * @param gradeToExecute Grade required to execute.
 */
AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "AForm " << name << " Constructor called" << std::endl;
	this->isSigned = 0;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (AForm::GradeTooLowException());
}

/**
 * @brief Default constructor for AForm.
 * 
 * Sets empty name and default grade requirements (150). Form unsigned.
 */
AForm::AForm() : name(""), gradeToExecute(150), gradeToSign(150)
{
	this->isSigned = 0;
	std::cout << "Default AForm Constructor called" << std::endl;
}

/**
 * @brief Destructor for AForm.
 * 
 * Prints destruction message.
 */
AForm::~AForm()
{
	std::cout << "Default AForm Destructor called" << std::endl;
}

/**
 * @brief Overloaded output stream operator for AForm.
 * 
 * Prints the form's name and its signing and execution grade requirements.
 * 
 * @param out Output stream.
 * @param classToPrint AForm instance to print.
 * @return std::ostream& Reference to output stream.
 */
std::ostream&	operator<<( std::ostream &out, AForm const &classToPrint )
{
	out << classToPrint.getName() << ", AForm grade to sign: " << classToPrint.getGradeToSign() << " grade to execute: " << classToPrint.getGradeToExecute() << std::endl;
	return (out);
}

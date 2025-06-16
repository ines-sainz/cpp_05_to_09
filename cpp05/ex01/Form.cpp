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

/**
 * @brief Exception message for grade too low in Form.
 * 
 * @return const char* Error message string.
 */
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief Exception message for grade too high in Form.
 * 
 * @return const char* Error message string.
 */
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * @brief Attempts to sign the form by the given Bureaucrat.
 * 
 * Throws GradeTooLowException if bureaucrat's grade is too low.
 * Sets isSigned flag to true on success.
 * 
 * @param bureaucrat Bureaucrat attempting to sign the form.
 */
void Form::beSigned( Bureaucrat bureaucrat )
{
	if ( this->gradeToSign < bureaucrat.getGrade())
		throw (Form::GradeTooLowException());
	this->isSigned = 1;
}

/**
 * @brief Gets the name of the form.
 * 
 * @return std::string The form's name.
 */
const std::string	Form::getName() const
{
	return (this->name);
}

/**
 * @brief Returns whether the form is signed.
 * 
 * @return true if signed, false otherwise.
 */
bool Form::getIsSigned() const
{
	return (this->isSigned);
}

/**
 * @brief Gets the grade required to sign the form.
 * 
 * @return int Grade required for signing.
 */
const int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

/**
 * @brief Gets the grade required to execute the form.
 * 
 * @return int Grade required for execution.
 */
const int Form::getGradeToExecute() const
{
	return (this->gradeToExecute);
}

/**
 * @brief Copy assignment operator overload.
 * 
 * Copies all fields from another Form, including const members
 * via const_cast.
 * 
 * @param before Form to copy from.
 * @return Form& Reference to this object.
 */
Form& Form::operator=( const Form& before )
{
	std::cout << "Copy Form Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.name;
	const_cast<int&>(this->gradeToExecute) = before.getGradeToExecute();
	const_cast<int&>(this->gradeToSign) = before.getGradeToSign();
	this->isSigned = before.isSigned;
	return (*this);
}

/**
 * @brief Copy constructor.
 * 
 * Copies all data from another Form, throws if grades invalid.
 * 
 * @param before Form to copy from.
 */
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

/**
 * @brief Parameterized constructor.
 * 
 * Initializes form with name and required grades, sets signed false.
 * Throws if grades are out of valid range [1,150].
 * 
 * @param name Name of the form.
 * @param gradeToSign Grade required to sign.
 * @param gradeToExecute Grade required to execute.
 */
Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << "Form " << name << " Constructor called" << std::endl;
	this->isSigned = 0;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (Form::GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (Form::GradeTooLowException());
}

/**
 * @brief Default constructor.
 * 
 * Initializes a form with default values and unsigned status.
 */
Form::Form() : name(""), gradeToExecute(150), gradeToSign(150)
{
	this->isSigned = 0;
	std::cout << "Default Form Constructor called" << std::endl;
}

/**
 * @brief Destructor.
 */
Form::~Form()
{
	std::cout << "Default Form Destructor called" << std::endl;
}

/**
 * @brief Stream insertion operator overload.
 * 
 * Prints form details: name, grade required to sign and execute.
 * 
 * @param out Output stream.
 * @param classToPrint Form to print.
 * @return std::ostream& Reference to output stream.
 */
std::ostream&	operator<<( std::ostream &out, Form const &classToPrint )
{
	out << classToPrint.getName() << ", Form grade to sign: " << classToPrint.getGradeToSign() << " grade to execute: " << classToPrint.getGradeToExecute() << std::endl;
	return (out);
}

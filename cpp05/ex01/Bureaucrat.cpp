/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:31:12 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/15 12:31:14 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * @brief Exception message for grade too low error.
 * 
 * @return const char* Error message string.
 */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief Exception message for grade too high error.
 * 
 * @return const char* Error message string.
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * @brief Attempts to sign a form if the bureaucrat's grade is sufficient.
 * 
 * Prints error if grade is too low or form is already signed. Otherwise,
 * signs the form and prints confirmation.
 * 
 * @param form Reference to the Form to be signed.
 */
void Bureaucrat::signForm( Form& form ) const
{
	if (form.getGradeToSign() < this->grade)
	{
		std::cout << "Bureaucrat " << this->name << " couldn't sign form " << form.getName() << " because is not in their level" << std::endl;
		return ;
	}
	if (form.getIsSigned() == 1)
	{
		std::cout << "Bureaucrat " << this->name << " couldn't sign form " << form.getName() << " because it is already signed" << std::endl;
		return ;
	}
	form.beSigned(*this);
	std::cout << "Bureaucrat " << this->name << " signed form " << form.getName() << std::endl;
}

/**
 * @brief Decreases the bureaucrat's grade by one, throws if too high.
 * 
 * Throws GradeTooHighException if grade is already at highest level (1).
 */
void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	this->grade--;
}

/**
 * @brief Increases the bureaucrat's grade by one, throws if too low.
 * 
 * Throws GradeTooLowException if grade is already at lowest level (150).
 */
void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	this->grade++;
}

/**
 * @brief Gets the current bureaucrat grade.
 * 
 * @return int The grade value.
 */
int Bureaucrat::getGrade() const
{
	return (this->grade);
}

/**
 * @brief Gets the bureaucrat's name.
 * 
 * @return const std::string The name string.
 */
const std::string Bureaucrat::getName() const
{
	return (this->name);
}

/**
 * @brief Copy assignment operator overload.
 * 
 * Copies name and grade from the right-hand Bureaucrat.
 * 
 * @param before The Bureaucrat to copy from.
 * @return Bureaucrat& Reference to this object.
 */
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& before )
{
	std::cout << "Copy Bureaucrat Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.getName();
	this->grade = before.getGrade();
	return (*this);
}

/**
 * @brief Copy constructor.
 * 
 * Copies the given Bureaucrat data into this object.
 * 
 * @param before The Bureaucrat to copy.
 */
Bureaucrat::Bureaucrat( const Bureaucrat& before ) : name(before.name)
{
	std::cout << "Copy Bureaucrat Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Parameterized constructor.
 * 
 * Constructs a Bureaucrat with a name and grade. Throws exceptions if
 * grade is out of range [1,150].
 * 
 * @param name The Bureaucrat's name.
 * @param grade The Bureaucrat's grade.
 */
Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name)
{
	std::cout << "Bureaucrat " << (std::string)this->name << " Constructor called" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

/**
 * @brief Default constructor.
 * 
 * Initializes Bureaucrat with empty name and lowest grade (150).
 */
Bureaucrat::Bureaucrat( void )
{
	this->grade = 150;
	(std::string)this->name = "";
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

/**
 * @brief Destructor.
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called" << std::endl;
}

/**
 * @brief Stream insertion operator overload.
 * 
 * Outputs the bureaucrat's name and grade in the format:
 * "Name, bureaucrat grade Grade".
 * 
 * @param out Output stream.
 * @param classToPrint Bureaucrat object to print.
 * @return std::ostream& Reference to the output stream.
 */
std::ostream	&operator<<( std::ostream &out, const Bureaucrat &classToPrint )
{
	out << classToPrint.getName() << ", bureaucrat grade " << classToPrint.getGrade();
	return (out);
}

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

/**
 * @brief Exception message for grade too low.
 * 
 * @return const char* Error message string.
 */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief Exception message for grade too high.
 * 
 * @return const char* Error message string.
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * @brief Increases the Bureaucrat's grade by 1.
 * 
 * @throws Bureaucrat::GradeTooHighException if grade becomes less than 1.
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
 * @brief Decreases the Bureaucrat's grade by 1.
 * 
 * @throws Bureaucrat::GradeTooLowException if grade becomes more than 150.
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
 * @brief Retrieves the current grade of the Bureaucrat.
 * 
 * @return int The Bureaucrat's grade.
 */
int Bureaucrat::getGrade() const
{
	return (this->grade);
}

/**
 * @brief Retrieves the name of the Bureaucrat.
 * 
 * @return const std::string The Bureaucrat's name.
 */
const std::string Bureaucrat::getName() const
{
	return (this->name);
}

/**
 * @brief Copy assignment operator for Bureaucrat.
 * 
 * @param before The Bureaucrat to copy from.
 * @return Bureaucrat& Reference to the assigned Bureaucrat.
 */
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& before )
{
	std::cout << "Copy Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.getName();
	this->grade = before.getGrade();
	return (*this);
}

/**
 * @brief Copy constructor for Bureaucrat.
 * 
 * @param before The Bureaucrat to copy from.
 */
Bureaucrat::Bureaucrat( const Bureaucrat& before ) : name(before.name)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Constructs a Bureaucrat with a name and grade.
 * 
 * @param name The name of the Bureaucrat.
 * @param grade The initial grade to assign.
 * @throws Bureaucrat::GradeTooHighException if grade < 1.
 * @throws Bureaucrat::GradeTooLowException if grade > 150.
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
 * @brief Default constructor for Bureaucrat.
 * 
 * Initializes with grade 150 and empty name.
 */
Bureaucrat::Bureaucrat( void )
{
	this->grade = 150;
	(std::string)this->name = "";
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

/**
 * @brief Destructor for Bureaucrat.
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called" << std::endl;
}

/**
 * @brief Output stream operator overload for Bureaucrat.
 * 
 * @param out The output stream.
 * @param classToPrint The Bureaucrat instance to print.
 * @return std::ostream& The modified output stream.
 */
std::ostream	&operator<<( std::ostream &out, const Bureaucrat &classToPrint )
{
	out << classToPrint.getName() << ", bureaucrat grade " << classToPrint.getGrade();
	return (out);
}

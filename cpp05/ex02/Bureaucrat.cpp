/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:31:12 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:40:26 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/**
 * @brief Exception message for grade too low error.
 * 
 * @return const char* Fixed message "Grade is too low".
 */
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief Exception message for grade too high error.
 * 
 * @return const char* Fixed message "Grade is too high".
 */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * @brief Execute the given form if it is signed.
 * 
 * Prints a message on success or if form is not signed.
 * Catches and prints exceptions thrown during execution.
 * 
 * @param form Reference to AForm to execute.
 */
void Bureaucrat::execute( AForm& form ) const
{
	if (form.getIsSigned() == 0)
	{
		std::cout << "Form is not signed" << std::endl;
		return ;
	}
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << this->name << " has executed the form" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/**
 * @brief Attempt to sign the given form.
 * 
 * Prints reasons if signing fails (insufficient grade or already signed).
 * Signs the form and prints confirmation if successful.
 * 
 * @param form Reference to AForm to sign.
 */
void Bureaucrat::signForm( AForm& form ) const
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
 * @brief Increment the bureaucrat's grade by 1.
 * 
 * Throws GradeTooHighException if grade is already 1 (highest).
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
 * @brief Decrement the bureaucrat's grade by 1.
 * 
 * Throws GradeTooLowException if grade is already 150 (lowest).
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
 * @brief Get the bureaucrat's grade.
 * 
 * @return int Current grade.
 */
int Bureaucrat::getGrade() const
{
	return (this->grade);
}

/**
 * @brief Get the bureaucrat's name.
 * 
 * @return const std::string Current name.
 */
const std::string Bureaucrat::getName() const
{
	return (this->name);
}

/**
 * @brief Assignment operator overload.
 * 
 * Copies the name and grade from another bureaucrat.
 * 
 * @param before Source bureaucrat to copy.
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
 * Initializes this bureaucrat as a copy of another.
 * 
 * @param before Bureaucrat to copy.
 */
Bureaucrat::Bureaucrat( const Bureaucrat& before ) : name(before.name)
{
	std::cout << "Copy Bureaucrat Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Parameterized constructor.
 * 
 * Initializes bureaucrat with given name and grade.
 * Throws exception if grade out of range [1,150].
 * 
 * @param name Bureaucrat's name.
 * @param grade Bureaucrat's grade.
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
 * Sets default name to empty and grade to 150 (lowest).
 */
Bureaucrat::Bureaucrat( void )
{
	this->grade = 150;
	(std::string)this->name = "";
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Prints a message on destruction.
 */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called" << std::endl;
}

/**
 * @brief Output stream operator overload.
 * 
 * Prints bureaucrat's name and grade.
 * 
 * @param out Output stream.
 * @param classToPrint Bureaucrat instance to print.
 * @return std::ostream& Reference to output stream.
 */
std::ostream	&operator<<( std::ostream &out, const Bureaucrat &classToPrint )
{
	out << classToPrint.getName() << ", bureaucrat grade " << classToPrint.getGrade();
	return (out);
}

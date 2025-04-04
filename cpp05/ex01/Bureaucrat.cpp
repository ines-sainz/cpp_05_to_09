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

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

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

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	this->grade--;
}


void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	this->grade++;
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}
Bureaucrat& Bureaucrat::operator=( const Bureaucrat& before )
{
	std::cout << "Copy Bureaucrat Assigment operator called" << std::endl;
	const_cast<std::string&>(this->name) = before.getName();
	this->grade = before.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat( const Bureaucrat& before ) : name(before.name)
{
	std::cout << "Copy Bureaucrat Constructor called" << std::endl;
	*this = before;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name)
{
	std::cout << "Bureaucrat " << (std::string)this->name << " Constructor called" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat( void )
{
	this->grade = 150;
	(std::string)this->name = "";
	std::cout << "Default Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat Destructor called" << std::endl;
}

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &classToPrint )
{
	out << classToPrint.getName() << ", bureaucrat grade " << classToPrint.getGrade();
	return (out);
}
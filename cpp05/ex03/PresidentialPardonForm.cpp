/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:41:00 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:02 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include  "Bureaucrat.hpp"

/**
 * @brief Executes the Presidential Pardon form.
 * 
 * Throws GradeTooLowException if the executor's grade is too low.
 * Prints a pardon message for the target if successful.
 * 
 * @param executor The Bureaucrat executing the form.
 */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getGradeToExecute() < executor.getGrade())
	{
		throw(AForm::GradeTooLowException());
	}
	std::cout << "Target " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/**
 * @brief Assignment operator overload.
 * 
 * Copies the target from another PresidentialPardonForm.
 * 
 * @param before The form to copy from.
 * @return PresidentialPardonForm& Reference to this form.
 */
PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& before)
{
	std::cout << "Copy PresidentialPardonForm Assigment operator called" << std::endl;
	this->target = before.target;
	return (*this);
}

/**
 * @brief Copy constructor.
 * 
 * Initializes this form as a copy of another, including base class.
 * 
 * @param before The form to copy from.
 */
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& before ) : AForm(before.getName(), before.getGradeToSign(), before.getGradeToExecute()), target(before.target)
{
	std::cout << "Copy PresidentialPardonForm Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Parameterized constructor.
 * 
 * Creates a form with a given target, predefined name and grade.
 * 
 * @param target The target of the pardon.
 */
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 72, 45)
{
	this->target = target;
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;

}

/**
 * @brief Default constructor.
 * 
 * Creates a form with default target and predefined name and grade.
 */
PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), target("target")
{
	this->target = "target";
	std::cout << "Default PresidentialPardonForm Constructor called" << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Prints a message when the form is destructed.
 */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm Destructor called" << std::endl;
}

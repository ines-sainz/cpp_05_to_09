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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getGradeToExecute() < executor.getGrade())
	{
		throw(AForm::GradeTooLowException());
	}
	std::cout << "Target " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& before)
{
	std::cout << "Copy PresidentialPardonForm Assigment operator called" << std::endl;
	this->target = before.target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& before ) : AForm(before.getName(), before.getGradeToSign(), before.getGradeToExecute()), target(before.target)
{
	std::cout << "Copy PresidentialPardonForm Constructor called" << std::endl;
	*this = before;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 72, 45)
{
	this->target = target;
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;

}

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), target("target")
{
	this->target = "target";
	std::cout << "Default PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm Destructor called" << std::endl;
}

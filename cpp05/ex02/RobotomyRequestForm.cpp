/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:41:16 by isainz-r          #+#    #+#             */
/*   Updated: 2025/01/20 15:41:17 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

/**
 * @brief Executes the Robotomy Request form.
 * 
 * Throws GradeTooLowException if executor's grade is too low.
 * Randomly announces success or failure of the robotomy on the target.
 * 
 * @param executor The Bureaucrat executing the form.
 */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getGradeToExecute() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	std::cout << "*Making drilling noises*\n";
	std::srand(static_cast<unsigned int>(std::time(0)));
	int random = rand();
	if (random % 2 == 0)
		std::cout << "Target " << target << " has been robotomized" << std::endl;
	else
		std::cout << "Target " << target << "robotomy has failed" << std::endl;
}

/**
 * @brief Assignment operator overload.
 * 
 * Copies the target from another RobotomyRequestForm.
 * 
 * @param before The form to copy from.
 * @return RobotomyRequestForm& Reference to this form.
 */
RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& before )
{
	std::cout << "Copy RobotomyRequestForm Assigment Operator called" << std::endl;
	this->target = before.target;
	return (*this);
}

/**
 * @brief Copy constructor.
 * 
 * Copies all members including base class from another form.
 * 
 * @param before The form to copy.
 */
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& before ) : AForm(before.getName(), before.getGradeToSign(), before.getGradeToExecute()), target(before.target)
{
	std::cout << "Copy RobotomyRequestForm Constructor called" << std::endl;
	*this = before;
}

/**
 * @brief Parameterized constructor.
 * 
 * Creates a form with a given target, and fixed name and grade values.
 * 
 * @param target The target to robotomize.
 */
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

/**
 * @brief Default constructor.
 * 
 * Creates a form with default target and fixed name and grades.
 */
RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), target("target")
{
	this->target = "target";
	std::cout << "Default RobotomyRequestForm Constructor called" << std::endl;
}

/**
 * @brief Destructor.
 * 
 * Prints a message when the form is destructed.
 */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm Destructor called" << std::endl;
}

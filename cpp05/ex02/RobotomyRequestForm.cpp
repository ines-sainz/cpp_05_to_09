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

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& before )
{
	std::cout << "Copy RobotomyRequestForm Assigment Operator called" << std::endl;
	this->target = before.target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& before ) : AForm(before.getName(), before.getGradeToSign(), before.getGradeToExecute()), target(before.target)
{
	std::cout << "Copy RobotomyRequestForm Constructor called" << std::endl;
	*this = before;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), target("target")
{
	this->target = "target";
	std::cout << "Default RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm Destructor called" << std::endl;
}

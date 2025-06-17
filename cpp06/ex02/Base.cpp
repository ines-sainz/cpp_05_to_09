/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:45:24 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/07 12:45:25 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * @brief Identifies the derived class type of a Base reference.
 *
 * Uses dynamic_cast to check if the reference refers to an A, B, or C object.
 *
 * @param p Reference to a Base object.
 */
void Base::identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A derived class" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B derived class" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C derived class" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	std::cout << "Not an A, B, or C derived class4" << std::endl;
}

/**
 * @brief Identifies the derived class type of a Base pointer.
 *
 * Uses dynamic_cast to check if the pointer refers to an A, B, or C object.
 *
 * @param p Pointer to a Base object.
 */
void Base::identify(Base* p)
{
	A*	a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A derived class" << std::endl;
		return ;
	}
	B*	b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B derived class" << std::endl;
		return ;
	}
	C*	c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C derived class" << std::endl;
		return ;
	}
	std::cout << "Not an A, B, or C derived class" << std::endl;
}

/**
 * @brief Randomly generates and returns a new derived class object.
 *
 * Randomly returns an instance of class A, B, or C as a Base pointer.
 *
 * @return Pointer to a randomly created derived class object.
 */
Base* Base::generate( void )
{
	Base	*base;

	std::srand(static_cast<unsigned int>(std::time(0)));
	int random = rand();
	if (random % 5 == 0)
		base = new A;
	else if (random % 2 == 0)
		base = new B;
	else
		base = new C;
	return (base);
}

/**
 * @brief Default constructor for class Base.
 *
 * Prints a message when an instance of Base is created.
 */
Base::Base( void )
{
	std::cout << "Default Base Constructor called" << std::endl;
}

/**
 * @brief Default destructor for class Base.
 *
 * Prints a message when an instance of Base is destroyed.
 */
Base::~Base()
{
	std::cout << "Default Base Destructor called" << std::endl;
}

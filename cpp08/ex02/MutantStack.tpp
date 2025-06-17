/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:47 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/18 17:22:52 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/**
 * @brief Assignment operator for MutantStack.
 * 
 * Assigns the contents of another MutantStack to this one by invoking
 * the base std::stack assignment operator.
 * 
 * @param before The MutantStack to assign from.
 * @return MutantStack<T>& Reference to this MutantStack.
 */
template<class T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack<T>& before )
{
	std::stack<T>::operator=(before);
	return (*this);
}

/**
 * @brief Copy constructor for MutantStack.
 * 
 * Initializes this MutantStack by copying from another. Calls the base
 * std::stack copy constructor and outputs a debug message.
 * 
 * @param before The MutantStack to copy from.
 */
template<class T>
MutantStack<T>::MutantStack( const MutantStack& before ) : std::stack<T>(before)
{
	std::cout << "Default MutantStack Copy Constructor called" << std::endl;
}

/**
 * @brief Default constructor for MutantStack.
 * 
 * Initializes an empty MutantStack and outputs a debug message.
 */
template<class T>
MutantStack<T>::MutantStack( void ) : std::stack<T>()
{
	std::cout << "Default MutantStack Constructor called" << std::endl;
}

/**
 * @brief Destructor for MutantStack.
 * 
 * Outputs a debug message upon destruction.
 */
template<class T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Default MutantStack Destructor called" << std::endl;
}

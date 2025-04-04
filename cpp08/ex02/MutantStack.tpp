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

template<class T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack<T>& before )
{
	std::stack<T>::operator=(before);
	return (*this);
}

template<class T>
MutantStack<T>::MutantStack( const MutantStack& before ) : std::stack<T>(before)
{
	std::cout << "Default MutantStack Copy Constructor called" << std::endl;
}

template<class T>
MutantStack<T>::MutantStack( void ) : std::stack<T>()
{
	std::cout << "Default MutantStack Constructor called" << std::endl;
}

template<class T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Default MutantStack Destructor called" << std::endl;
}

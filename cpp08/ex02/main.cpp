/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:30 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/18 17:22:35 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> mlist;

	mstack.push(5);
	mstack.push(17);
	mlist.push_front(5);
	mlist.push_front(17);

	std::cout << "mstack top " << mstack.top() << std::endl;
	std::cout << "mlist top "<< mlist.front() << std::endl;

	mstack.pop();
	mlist.pop_front();

	std::cout << std::endl;

	std::cout << "size_stack " << mstack.size() << std::endl;
	std::cout << "size_list " << mlist.size() << std::endl;

	std::cout << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << "mstack_element " << *it << std::endl;
		++it;
	}

	std::cout << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator it_list = mlist.begin();
	std::list<int>::iterator ite_list = mlist.end();

	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << "mlist_element " << *it_list << std::endl;
		++it_list;
	}

	std::stack<int> s(mstack);
	std::list<int> s_list(mlist);
	return (0);

}

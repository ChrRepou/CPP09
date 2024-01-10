/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:21:10 by crepou            #+#    #+#             */
/*   Updated: 2024/01/10 23:47:56 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	//PmergeMe	*pm = new PmergeMe();
	
	//pm->fillVector();
	//pm->printVector(pm->_container);
	//pm->mergeSort(pm->_container, 0, pm->_size - 1);
	//pm->printVector(pm->_container);
	//delete pm;

	if (argc < 2)
	{
		std::cout << "Usage: ./a.out [integers]" << std::endl;
		return (1);
	}

	std::vector<int>	container;
	std::deque<int>		dqContainer;
	int					i = 0;
	while (++i < argc)
	{
		std::string str(argv[i]);
		if (str.empty())
		{
			std::cout << "Error: empty argumment" << std::endl;
			return (1);
		}	
		int number = atoi(argv[i]);
		if (number < 0)
		{
			std::cout << "Error: wrong argument (negative number or too big) " << std::endl;
			return (1);
		}
		container.push_back(atoi(argv[i]));
		dqContainer.push_back(atoi(argv[i]));
	}
	
	PmergeMe	pm(container);
	PmergeMe	pm2(dqContainer);
	
	std::cout << "Before: ";
	pm.printVector();
	std::cout << "After: ";
	
	pm.sortVector();
	pm2.sortDeque();
	
	int elems = container.size();
	pm.printVector();
	
	std::cout << "Time to process a range of " << elems << " elements with std::vector : " << std::fixed 
		<< pm.getVectorTime() << std::setprecision(5) << " us" << std::endl;
	std::cout << "Time to process a range of " << elems << " elements with std::deque : " << std::fixed 
		<< pm2.getDequeTime() << std::setprecision(5) << " us" << std::endl;

	return (0);
}
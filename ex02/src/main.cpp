/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:21:10 by crepou            #+#    #+#             */
/*   Updated: 2023/12/11 03:30:27 by crepou           ###   ########.fr       */
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
	}

	PmergeMe	pm(container);
	std::cout << "Before sorting: ";
	pm.printVector();
	pm.sortVector();
	//pm.fillPendChainVector();
	//pm.fillMainChainVector();
	
	//std::cout << "After sorting: ";
	//pm.printVector();
	//pm.sortVector();
	//std::cout << "After merge sorting: ";
	//pm.printVector();

	return (0);
}
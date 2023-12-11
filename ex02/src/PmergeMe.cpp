/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:13:37 by crepou            #+#    #+#             */
/*   Updated: 2023/12/11 03:37:53 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _size(0), _indexJacobsthalNum(0)
{
	return ;
}

PmergeMe::PmergeMe(std::vector<int> container) : _mainChainVector(0), _pendChainVector(0)
{
	this->_container = container;
	this->_size = 0;
	this->_indexJacobsthalNum = 1;
	this->_size = container.size();
	this->_endOfMainChainVector = 0;
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &obj)
{
	if (this != &obj)
	{
		this->_container = obj._container;
	}
	return (*this);
}

void	PmergeMe::printVector( void )
{
	std::vector<int>::iterator	it;

	it = _container.begin();
	while (it != _container.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	PmergeMe::sortPairsVector( void )
{
	std::vector<int>::iterator	it;
	int							tmp;

	it = this->_container.begin();
	while (it != this->_container.end())
	{
		if (it + 1 != this->_container.end())
		{
			if (*it < *(it + 1))
			{
				tmp = *it;
				*it = *(it + 1);
				*(it + 1) = tmp;
			}
		}
		if (it + 1 == this->_container.end())
			break;
		it += 2;
	}
}

void	PmergeMe::merge(std::vector<int> &container, int start, int middle, int end)
{
	int		i;
	int		j;
	int		k;
	int		n1;
	int		n2;
	int		*L;
	int		*R;

	n1 = middle - start + 1;
	n2 = end - middle;
	L = new int[n1];
	R = new int[n2];
	i = 0;
	while (i < n1)
	{
		L[i] = container[start + i];
		i++;
	}
	j = 0;
	while (j < n2)
	{
		R[j] = container[middle + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			container[k] = L[i];
			i++;
		}
		else
		{
			container[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		container[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		container[k] = R[j];
		j++;
		k++;
	}
	delete [] L;
	delete [] R;
}

void	PmergeMe::mergeSort(std::vector<int> &container, int start, int end)
{
	if (start < end)
	{
		int middle = start + (end - start) / 2;
		mergeSort(container, start, middle);
		mergeSort(container, middle + 1, end);
		merge(container, start, middle, end);
	}
}

void	PmergeMe::sortVector()
{
	int _jacobsthalNum[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

	fillMainChainVector();
	fillPendChainVector();
	while (_pendChainVector.size() > 0)
	{
		int nextJacobsthalNum = _jacobsthalNum[_indexJacobsthalNum];
		int i = _jacobsthalNum[_indexJacobsthalNum - 1];
		std::cout << "Next Jacobsthal number: " << nextJacobsthalNum << std::endl;
		_indexJacobsthalNum++;
		while (!_pendChainVector.empty() && i < nextJacobsthalNum && nextJacobsthalNum < _size)
		{
			int num = _pendChainVector[nextJacobsthalNum];
			std::cout << "Inserting " << num << std::endl;
			binaryInsertionSort(num);
			_pendChainVector.erase(_pendChainVector.begin() + nextJacobsthalNum - 1);
			std::cout << "Main chain: ";
			printVec(_mainChainVector);
			std::cout << "Pend chain: ";
			printVec(_pendChainVector);
		}
	}
}

void	PmergeMe::binaryInsertionSort(int target)
{
	int		start;
	int		end;
	int		middle;

	start = 0;
	end = _size - 1;
	while (start <= _endOfMainChainVector)
	{
		middle = start + (_endOfMainChainVector - start) / 2;
		if (_mainChainVector[middle] == target)
		{
			_mainChainVector.insert(_mainChainVector.begin() + middle, target);
			return ;
		}
		else if (_mainChainVector[middle] < target)
			start = middle + 1;
		else
			_endOfMainChainVector = middle - 1;
	}
	_mainChainVector.insert(_mainChainVector.begin() + start, target);
}

void	PmergeMe::switchPairs(int index1Large, int index1Small, int index2Large, int index2Small)
{
	int		tmp;

	tmp = _container[index1Large];
	_container[index1Large] = _container[index2Large];
	_container[index2Large] = tmp;
	tmp = _container[index1Small];
	_container[index1Small] = _container[index2Small];
	_container[index2Small] = tmp;
}

void	PmergeMe::fillMainChainVector( void )
{
	int		i = 0;
	
	sortPairsVector();
	std::vector<int>::iterator	it = _container.begin();
	while (it != _container.end())
	{
		if (i % 2 == 0)
			_mainChainVector.push_back(*it);
		it++;
		i++;
	}
	if (_container.size() % 2 == 1)
		_mainChainVector.pop_back();
	quicksort(_mainChainVector, 0, _mainChainVector.size() - 1);
	_endOfMainChainVector = _mainChainVector.size() - 1;
	
}


void	PmergeMe::fillPendChainVector( void )
{
	int		i = 0;
	
	sortPairsVector();
	std::vector<int>::iterator	it = _container.begin();
	while (it != _container.end())
	{
		if (i % 2 == 1)
			_pendChainVector.push_back(*it);
		it++;
		i++;
	}

	if (_container.size() % 2 == 1)
		_pendChainVector.push_back(_container[_container.size() - 1]);
	std::cout << "Pend chain: ";
	printVec(_pendChainVector);
}

void PmergeMe::printVec(std::vector<int> vec)
{
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}
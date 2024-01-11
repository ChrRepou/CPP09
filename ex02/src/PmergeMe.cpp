/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:13:37 by crepou            #+#    #+#             */
/*   Updated: 2024/01/11 01:39:57 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _indexJacobsthalNum(0), _size(0), _vectorTime(0)
{
	return ;
}

PmergeMe::PmergeMe(std::vector<int> container) : _mainChainVector(0), _pendChainVector(0), _vectorTime(0)
{
	this->_container = container;
	this->_indexJacobsthalNum = 1;
	this->_size = container.size();
	return ;
}

PmergeMe::PmergeMe(std::deque<int> container) : _dqMainChain(0), _dqPendChain(0), _dqTime(0)
{
	this->_dqContainer = container;
	this->_indexJacobsthalNum = 1;
	this->_dqSize = container.size();
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

void	PmergeMe::printDeque( void )
{
	std::deque<int>::iterator	it;

	it = _dqContainer.begin();
	while (it != _dqContainer.end())
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

void	PmergeMe::sortPairsDeque( void )
{
	std::deque<int>::iterator	it;
	int							tmp;

	it = this->_dqContainer.begin();
	while (it != this->_dqContainer.end())
	{
		if (it + 1 != this->_dqContainer.end())
		{
			if (*it < *(it + 1))
			{
				tmp = *it;
				*it = *(it + 1);
				*(it + 1) = tmp;
			}
		}
		if (it + 1 == this->_dqContainer.end())
			break;
		it += 2;
	}
}

void	PmergeMe::sortVector()
{
	time_t	start, end;
	start = clock();
	int _jacobsthalNum[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

	fillMainChainVector();
	fillPendChainVector();
	_size = _mainChainVector.size();
	int nextJacobsthalNum = _jacobsthalNum[_indexJacobsthalNum];
	int i = _jacobsthalNum[_indexJacobsthalNum - 1];
	_indexJacobsthalNum++;
	int pendChainSize = _pendChainVector.size();
	while (!_pendChainVector.empty() && i < nextJacobsthalNum && nextJacobsthalNum < pendChainSize)
	{
		while (nextJacobsthalNum > -1 && pendChainSize != 0)
		{
			int num = _pendChainVector[nextJacobsthalNum];
			binaryInsertionSort(num);
			_size++;
			_pendChainVector.erase(_pendChainVector.begin() + nextJacobsthalNum);
			pendChainSize = _pendChainVector.size();
			nextJacobsthalNum--;
		}
		if (pendChainSize == 0)
			break ;
		nextJacobsthalNum = _jacobsthalNum[_indexJacobsthalNum];
		i = _jacobsthalNum[_indexJacobsthalNum - 1];
		_indexJacobsthalNum++;
	}
	while (_pendChainVector.size() > 0)
	{
		int num = _pendChainVector.back();
		binaryInsertionSort(num);
		_size++;
		_pendChainVector.pop_back();
	}
	_container = _mainChainVector;
	end = clock();
	_vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void	PmergeMe::sortDeque()
{
	time_t	start, end;
	start = clock();
	int _jacobsthalNum[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

	fillMainChainDeque();
	fillPendChainDeque();
	_dqSize = _dqMainChain.size();
	int nextJacobsthalNum = _jacobsthalNum[_indexJacobsthalNum];
	int i = _jacobsthalNum[_indexJacobsthalNum - 1];
	_indexJacobsthalNum++;
	int pendChainSize = _dqPendChain.size();
	while (!_dqPendChain.empty() && i < nextJacobsthalNum && nextJacobsthalNum < pendChainSize)
	{
		while (nextJacobsthalNum > -1 && pendChainSize != 0)
		{
			int num = _dqPendChain.at(nextJacobsthalNum);
			binaryInsertionSortDq(num);
			_dqSize++;
			_dqPendChain.erase(_dqPendChain.begin() + nextJacobsthalNum);
			pendChainSize = _dqPendChain.size();
			nextJacobsthalNum--;
		}
		if (pendChainSize == 0)
			break ;
		nextJacobsthalNum = _jacobsthalNum[_indexJacobsthalNum];
		i = _jacobsthalNum[_indexJacobsthalNum - 1];
		_indexJacobsthalNum++;
	}
	while (_dqPendChain.size() > 0)
	{
		int num = _dqPendChain.back();
		binaryInsertionSortDq(num);
		_dqSize++;
		_dqPendChain.pop_back();
	}
	_dqContainer = _dqMainChain;
	end = clock();
	_dqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void	PmergeMe::binaryInsertionSort(int target)
{
	int		start;
	int		end;
	int		middle;

	start = 0;
	end = _size - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (_mainChainVector[middle] == target)
		{
			_mainChainVector.insert(_mainChainVector.begin() + middle, target);
			return ;
		}
		else if (_mainChainVector[middle] < target)
			start = middle + 1;
		else
			end = middle - 1;
	}
	_mainChainVector.insert(_mainChainVector.begin() + start, target);
}

void	PmergeMe::binaryInsertionSortDq(int target)
{
	int		start;
	int		end;
	int		middle;

	start = 0;
	end = _dqSize - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (_dqMainChain.at(middle) == target)
		{
			_dqMainChain.insert(_dqMainChain.begin() + middle, target);
			return ;
		}
		else if (_dqMainChain.at(middle) < target)
			start = middle + 1;
		else
			end = middle - 1;
	}
	_dqMainChain.insert(_dqMainChain.begin() + start, target);
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

void	PmergeMe::switchPairsDq(int index1Large, int index1Small, int index2Large, int index2Small)
{
	int		tmp;

	tmp = _dqContainer.at(index1Large);
	_dqContainer.at(index1Large) = _dqContainer.at(index2Large);
	_dqContainer.at(index2Large) = tmp;
	tmp = _dqContainer.at(index1Small);
	_dqContainer.at(index1Small) = _dqContainer.at(index2Small);
	_dqContainer.at(index2Small) = tmp;
}

void	PmergeMe::fillMainChainVector( void )
{
	int		i = 0;
	
	sortPairsVector();
	std::vector<int>::iterator	it = _container.begin();
	_mainChainVector.reserve(_size / 2);
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
}

void PmergeMe::fillMainChainDeque( void )
{
	int		i = 0;
	
	sortPairsDeque();
	std::deque<int>::iterator	it = _dqContainer.begin();
	while (it != _dqContainer.end())
	{
		if (i % 2 == 0)
			_dqMainChain.push_back(*it);
		it++;
		i++;
	}
	if (_dqContainer.size() % 2 == 1)
		_dqMainChain.pop_back();
	quicksortDq(_dqMainChain, 0, _dqMainChain.size() - 1);
}


void	PmergeMe::fillPendChainVector( void )
{
	int		i = 0;
	
	sortPairsVector();
	std::vector<int>::iterator	it = _container.begin();
	if (_size % 2 == 0)
		_pendChainVector.reserve(_size / 2);
	else
		_pendChainVector.reserve(_size / 2 + 1);
	while (it != _container.end())
	{
		if (i % 2 == 1)
			_pendChainVector.push_back(*it);
		it++;
		i++;
	}

	if (_container.size() % 2 == 1)
		_pendChainVector.push_back(_container[_container.size() - 1]);
}

void	PmergeMe::fillPendChainDeque( void )
{
	int		i = 0;
	
	sortPairsDeque();
	std::deque<int>::iterator	it = _dqContainer.begin();
	while (it != _dqContainer.end())
	{
		if (i % 2 == 1)
			_dqPendChain.push_back(*it);
		it++;
		i++;
	}

	if (_dqContainer.size() % 2 == 1)
		_dqPendChain.push_back(_dqContainer.at(_dqContainer.size() - 1));
}

double PmergeMe::getVectorTime()
{
	return _vectorTime;
}

double PmergeMe::getDequeTime()
{
	return _dqTime;
}
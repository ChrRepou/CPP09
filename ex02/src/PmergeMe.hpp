/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:13:38 by crepou            #+#    #+#             */
/*   Updated: 2024/01/11 01:40:01 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <iomanip>
# include <deque>


template <typename T>
int partition(std::vector<T>& v, int low, int high) {
    // Choose the rightmost element as the pivot
    T pivot = v[high];

    // Index of the smaller element
    int i = low - 1;

    // Traverse through the vector
    for (int j = low; j <= high - 1; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (v[j] <= pivot) {
            // Swap v[i] and v[j]
            ++i;
            std::swap(v[i], v[j]);
        }
    }

    // Swap v[i + 1] and v[high] (move the pivot to its correct position)
    std::swap(v[i + 1], v[high]);

    // Return the pivot index
    return i + 1;
}

template <typename T>
int partitionDq(std::deque<T>& dq, int low, int high) {
	T pivot = dq.at(high);
	int i = low - 1;
	
	for (int j = low; j <= high - 1; ++j) {
		if (dq.at(j) <= pivot) {
			++i;
			std::swap(dq.at(i), dq.at(j));
		}
	}

	std::swap(dq.at(i + 1), dq.at(high));
	return i + 1;
}

template <typename T>
void quicksort(std::vector<T>& v, int low, int high) {
    if (low < high) {
        // Partition the vector and get the pivot index
        int pivotIndex = partition(v, low, high);

        // Recursively sort the sub-vectors before and after the pivot
        quicksort(v, low, pivotIndex - 1);
        quicksort(v, pivotIndex + 1, high);
    }
}

template <typename T>
void quicksortDq(std::deque<T>& dq, int low, int high) {
	if (low < high) {
		int pivotIndex = partitionDq(dq, low, high);
		quicksortDq(dq, low, pivotIndex - 1);
		quicksortDq(dq, pivotIndex + 1, high);
	}
}

class PmergeMe
{
	private:
		int					_indexJacobsthalNum;
		
		//vector variables
		std::vector<int>	_container;
		int					_size;
		std::vector<int>	_mainChainVector;
		std::vector<int>	_pendChainVector;
		double				_vectorTime;

		//deque variables
		std::deque<int>		_dqContainer;
		int					_dqSize;
		std::deque<int>		_dqMainChain;
		std::deque<int>		_dqPendChain;
		double				_dqTime;

	public:
		PmergeMe(void);
		PmergeMe(std::vector<int> container);
		PmergeMe(std::deque<int> container);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe	&operator=(PmergeMe const &obj);
		
		void		printVector( void );
		void		printDeque( void );
		
		void		sortVector( void );
		void		sortDeque( void );
		
		void		binaryInsertionSort(int target);
		void		binaryInsertionSortDq(int target);
		
		void		switchPairs(int index1Large, int index1Small, int index2Large, int index2Small);
		void		switchPairsDq(int index1Large, int index1Small, int index2Large, int index2Small);

		void		fillMainChainVector( void );
		void		fillMainChainDeque( void );
		
		void		fillPendChainVector( void );
		void		fillPendChainDeque( void );

		void		sortPairsVector( void );
		void		sortPairsDeque( void );
		
		double		getVectorTime( void );
		double		getDequeTime( void );
};

#endif
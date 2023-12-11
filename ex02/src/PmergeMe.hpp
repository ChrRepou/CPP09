/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:13:38 by crepou            #+#    #+#             */
/*   Updated: 2023/12/11 03:29:29 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>

//# define JACOBSTHAL_NUM {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525}


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
void quicksort(std::vector<T>& v, int low, int high) {
    if (low < high) {
        // Partition the vector and get the pivot index
        int pivotIndex = partition(v, low, high);

        // Recursively sort the sub-vectors before and after the pivot
        quicksort(v, low, pivotIndex - 1);
        quicksort(v, pivotIndex + 1, high);
    }
}

class PmergeMe
{
	private:
		std::vector<int>	_container;
		int					_size;
		int					_indexJacobsthalNum;
		std::vector<int>	_mainChainVector;
		std::vector<int>	_pendChainVector;
		int					_endOfMainChainVector;
	public:
		PmergeMe(void);
		PmergeMe(std::vector<int> container);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe	&operator=(PmergeMe const &obj);

		void		merge(std::vector<int> &container, int start, int middle, int end);
		void		mergeSort(std::vector<int> &container, int start, int end);
		void		printVector( void );
		void		sortVector( void );
		void 		binaryInsertionSort(int target);
		void 		switchPairs(int index1Large, int index1Small, int index2Large, int index2Small);
		void 		fillMainChainVector( void );
		void 		fillPendChainVector( void );

		void 		fillVector();
		void		sortPairsVector( void );
		void		printVec( std::vector<int> vec );
};

#endif
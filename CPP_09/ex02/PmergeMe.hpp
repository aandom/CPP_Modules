/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:10:31 by aandom            #+#    #+#             */
/*   Updated: 2023/10/23 09:10:31 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <vector>
# include <list>
# include <iostream>
# include <limits>
# include <exception>

class PmergeMe
{
    public:
        template <typename T>
        static void    pmergeSort(T& C) {
            // mergeInsertionSort(C, 0, C.size() - 1);
            mergeInsertionSort(C);
        }

    private:
        PmergeMe();
        PmergeMe(const PmergeMe & src);
        ~PmergeMe();

        PmergeMe & operator=(const PmergeMe & src);

        static  const int minSize = 8; 

        template<typename T>
        static void insertionSort(T& container) {
            int tmp;
            typename T::iterator it;
            typename T::iterator prev;
            typename T::iterator j;

            for (it = container.begin(); it != container.end(); ++it) {
                tmp = *it;
                j = it;
                while (j != container.begin()) {
                    prev = j;
                    --prev;
                    if (tmp < *prev) {
                        *j = *prev;
                        --j;
                    }
                    else
                        break;
                }
                *j = tmp;
          }
        }

        template <typename T>
        static void mergeInsertionSort(T& container)
        {
            size_t	len = container.size();

            if (len > minSize)
            {
                typename T::iterator begin = container.begin();
                typename T::iterator midPoint = container.begin();
                std::advance(midPoint, container.size() / 2);
                typename T::iterator end = container.end();

                T leftBranch(begin, midPoint);
                T rightBranch(midPoint, end);

                mergeInsertionSort(leftBranch);
                mergeInsertionSort(rightBranch);
                std::merge(leftBranch.begin(), leftBranch.end(), rightBranch.begin(), rightBranch.end(), container.begin());
            }
            else
                insertionSort(container);
        }
};

int  checkInt(std::string const & input);

# endif




        // template <typename T>
        // static void    insertionSort(T& container, int start, int end) {
        //       for (int i = start + 1; i < end; i++) {
        //         int tmp = container[i];
        //         int j = i - 1;

        //         // Compare tmp with each element on the left of it until an element smaller than
        //         // it is found.
        //         // For descending order, change tmp<array[j] to tmp>array[j].
        //         while (tmp < container[j] && j >= start) {
        //             container[j + 1] = container[j];
        //             --j;
        //         }
        //         container[j + 1] = tmp;
        //       }
        // }

        // template <typename T>
        // static void    mergeSort(T& container, int start, int midPoint, int end) {
        //     int i, j, k;
        //     int leftLen = midPoint - start + 1;
        //     int rightLen = end - midPoint;

        //     // Creating two temp branches of type T to store left and right braches.
        //     T leftCont(leftLen), rightCont(rightLen);

        //     // Copying the data from the actual Container to left and right temp branches.
        //     for (int a = 0; a < leftLen; a++) {
        //         leftCont[a] = container[start + a];
        //     }
        //     for (int a = 0; a < rightLen; a++) {
        //         rightCont[a] = container[midPoint + 1 + a];
        //     }

        //     i = 0; 
        //     j = 0; 
        //     k = start;    // Starting index of merged subcontaineray.

        //     while (i < leftLen && j < rightLen) {
        //         // Checking and placing the smaller number of both temp branches into the main container.
        //         if (leftCont[i] <= rightCont[j]) {
        //             container[k] = leftCont[i];
        //             i++;
        //         } else {
        //             container[k] = rightCont[j];
        //             j++;
        //         }
        //         k++;
        //     }

        //     // copying the remaining elements of the temp branches to the main container.
        //     while (i < leftLen) {
        //         container[k] = leftCont[i];
        //         k++;
        //         i++;
        //     }
        //     while (j < rightLen) {
        //         container[k] = rightCont[j];
        //         k++;
        //         j++;
        //     }
        // }

        // template <typename T>
        // static void    mergeInsertionSort(T& container, int start, int end) {
        //     if (start < end) {
        //         if (end - start > minSize) {
        //             insertionSort(container, start, end);
        //         }
        //         else {
        //             int midPoint = start + (( end - start) / 2);
        //             // Calling the function mergeSort() recursively and breaking down the given array into smaller sub arrays.
        //             // mergeSort(arr, low, mid);
        //             // mergeSort(arr, mid + 1, end);
        //             mergeInsertionSort(container, start, midPoint);
        //             mergeInsertionSort(container, midPoint + 1, end);

        //             // Calling the merge() function to merge the sorted subarrays into the main array.
        //             // merge(arr, low, mid, high);
        //             mergeSort(container, start, midPoint, end);  
        //         }
        //     }
        // }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:11:10 by aandom            #+#    #+#             */
/*   Updated: 2023/10/23 09:11:10 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

template <class T>
void printContainer(const T &container)
{
	typedef typename T::const_iterator const_iterator;

	for (const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}


int main (int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (0);
    }

    std::vector<int> myvect;
    // std::list<int> mylist;
    std::deque<int> mydeque;

    int num;
    for (int i = 1; i < ac; i++)
    {
        num = checkInt(av[i]);
        if (num < 0) {
            std::cerr << "Error: Invalid Input" << std::endl;
            return (0);
        }
        myvect.push_back(num);
        // mylist.push_back(num);
        mydeque.push_back(num);
    }

    std::cout << "Before:\t";
    printContainer(myvect);
    PmergeMe::pmergeSort(myvect);
    std::cout << "After:\t";
    printContainer(myvect);

    // std::cout << "Before:\t";
    // printContainer(mylist);
    // PmergeMe::pmergeSort(mylist);
    // std::cout << "After:\t";
    // printContainer(mylist);

    std::cout << "Before:\t";
    printContainer(mydeque);
    PmergeMe::pmergeSort(mydeque);
    std::cout << "After:\t";
    printContainer(mydeque);
    
    
}
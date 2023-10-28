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

    std::cout << "[ ";
	for (const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
    std::cout << "]";
	std::cout << std::endl;
}

template <typename T>
double    sortContainer(T& Container) {
    std::cout << "Before\t: ";
    printContainer(Container);
    clock_t timeStart = clock();
    PmergeMe::pmergeSort(Container);
    clock_t timeEnd = clock();
    std::cout << "After\t: ";
    printContainer(Container);

    double time = static_cast<double> ((timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return (time);

    // std::cout << "Time to process a range of " << Container.size() << " elements with std::"
    //           << type << "<int> \t: " << time << "\tus" << std::endl;
}


int main (int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (0);
    }

    std::vector<int> myvect;
    std::list<int> mylist;
    std::deque<int> mydeque;

    int     num;
    for (int i = 1; i < ac; i++)
    {
        num = checkInt(av[i]);
        if (num < 0) {
            std::cerr << "Error: Invalid Input" << std::endl;
            return (0);
        }
        myvect.push_back(num);
        mylist.push_back(num);
        // mydeque.push_back(num);
    }

    double vectTime = sortContainer(myvect);
    double listTime = sortContainer(mylist);
    // double dequeTime = sortContainer(mydeque);

    std::cout << std::endl;
    std::cout << "Time to process a range of " << myvect.size() << " elements with std::vector<int> \t: " << vectTime << "\tus" << std::endl;
    std::cout << "Time to process a range of " << mylist.size() << " elements with std::list<int> \t: " << listTime << "\tus" << std::endl;
    // std::cout << "Time to process a range of " << mydeque.size() << " elements with std::deque<int> \t: " << dequeTime << "\tus" << std::endl;
}
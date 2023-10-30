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
void printContainer(const T &container) {
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
    std::cout << std::endl;
    clock_t timeStart = clock();
    PmergeMe::pmergeSort(Container);
    clock_t timeEnd = clock();
    std::cout << "After\t: ";
    printContainer(Container);
    std::cout << std::endl;

    double time = static_cast<double> ((timeEnd - timeStart)) / CLOCKS_PER_SEC;
    return (time);

    // std::cout << "Time to process a range of " << Container.size() << " elements with std::"
    //           << type << "<int> \t: " << time << "\tus" << std::endl;
}

template <typename T>
void    pushnumbers(T& Container, int ac, char **av) {

    int     num;
    for (int i = 1; i < ac; i++)
    {
        num = checkInt(av[i]);
        Container.push_back(num);
    }
}

template <typename T>
double    processContainer(T& Container, int ac, char **av) {
    clock_t timeStart = clock();

    pushnumbers(Container, ac, av);

    std::cout << "Before\t: ";
    printContainer(Container);

    PmergeMe::pmergeSort(Container);

    std::cout << "After\t: ";
    printContainer(Container);

    clock_t timeEnd = clock();

    double time = static_cast<double> ((timeEnd - timeStart)) / CLOCKS_PER_SEC ;
    return (time);

}





int main (int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (0);
    }
    if (ac > 10001) {
        std::cerr << ac << std::endl;
        std::cerr << "Error: too many arguments" << std::endl;
        return (0);
    }

    std::vector<int> myvect;
    std::list<int> mylist;
    std::deque<int> mydeque;

    // std::vector<int> myvect2;
    // std::list<int> mylist2;
    // std::deque<int> mydeque2;

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

    std::cout << YELLOW << "---- Sorting with Vector ---- " << RESET << std::endl;
    double vectTime = sortContainer(myvect);
    std::cout << YELLOW << "---- Sorting with List ----" << RESET << std::endl;
    double listTime = sortContainer(mylist);

    // std::cout << YELLOW << "---- Sorting with Deque ----" << RESET << std::endl;
    // double dequeTime1 = sortContainer(mydeque);


    // double vectTime2 = processContainer(myvect2, ac, av);
    // double listTime2 = processContainer(mylist2, ac, av);
    // double dequeTime = processContainer(mydeque, ac, av);

    // std::cout << std::endl;
    std::cout << "Time to process a range of " << myvect.size() << " elements with std::vector  : " << vectTime * 1000 << "\tms" << std::endl;
    std::cout << "Time to process a range of " << mylist.size() << " elements with std::list    : " << listTime * 1000 << "\tms" << std::endl;
    // std::cout << "Time to process a range of " << mydeque.size() << " elements with std::deque<int> \t: " << dequeTime << "\tus" << std::endl;

    // std::cout << "Time to process a range of1 " << myvect.size() << " elements with std::vector<int> \t: " << vectTime2 * 1000  << "\tms" << std::endl;
    // std::cout << "Time to process a range of1 " << mylist.size() << " elements with std::list<int> \t: " << listTime2 * 1000 << "\tms" << std::endl;
}
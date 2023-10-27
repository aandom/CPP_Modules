/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:58:00 by aandom            #+#    #+#             */
/*   Updated: 2023/10/19 09:58:00 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>


template <typename T, typename C>
void printStack(std::stack<T, C> s)
{
    if (s.empty())
        return;
    T x = s.top();
 
    s.pop();
    printStack(s);
    std::cout << x << ' ';
    s.push(x);
}

template <typename T, typename C>
void	printMutantStack(MutantStack<T, C> mstack, std::string name) {

	typename MutantStack<T, C>::const_iterator it = mstack.begin();
	typename MutantStack<T, C>::const_iterator ite = mstack.end();
    std::cout << name << " = [ ";
	for (; it != ite; ++it)
		std::cout << *it << " ";
    std::cout << "]";
    std::cout << std::endl;
    std::cout << std::endl;
}

template <typename T, typename C>
void	testConstIterator(MutantStack<T, C> & mstack) {

    std::cout << "/ --- const_iterator --- /" << std::endl;
	typename MutantStack<T, C>::const_iterator it = mstack.begin();
	typename MutantStack<T, C>::const_iterator ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
	std::cout << std::endl;
	std::cout << std::endl;

    // try {
    //     it = mstack.begin();
    //     while (it != ite) {
    //         std::cout << "before : [" << *it << "] \t";
    //         *it = *it + 1;
    //         std::cout << "after : [" << *it << "] " << std::endl;
    //         ++it;
    //     }
	//     std::cout << std::endl;
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }
}

template <typename T, typename C>
void	testIterator(MutantStack<T, C> & mstack) {

    std::cout << "/ --- iterator --- /" << std::endl;
	typename MutantStack<T, C>::iterator it = mstack.begin();
	typename MutantStack<T, C>::iterator ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << "[" << *it << "] ";
    std::cout << std::endl;
    std::cout << std::endl;

    it = mstack.begin();
    while (it != ite) {
        std::cout << "before : [" << *it << "] \t\t";
        *it = *it + static_cast<T>(1);

        std::cout << "after : [" << *it << "] " << std::endl;
        ++it;
    }
	std::cout << std::endl;
}

int main()
{
    std::cout << "/ ***** MutantStack ***** /" << std::endl;

    MutantStack<int> mystack;

    mystack.push(5);
    mystack.push(17);
    mystack.push(3);
    mystack.push(5);
    mystack.push(737);
    mystack.push(0);

    printMutantStack(mystack, "mystack");
    testConstIterator(mystack);
    testIterator(mystack);
    printMutantStack(mystack, "mystack");

    std::stack<int> s(mystack);
    std::cout << std::endl << "copied Stack = [ ";
    printStack(s);
    std::cout << "]" << std::endl;

}


// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }
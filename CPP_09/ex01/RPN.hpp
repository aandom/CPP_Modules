/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:11:22 by aandom            #+#    #+#             */
/*   Updated: 2023/10/23 09:11:22 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <algorithm>
# include <stack>
# include <string>
# include <iostream>

class RPN
{
    public:
        int computeRPN(const std::string & input);

    private:
        RPN();
        RPN(const RPN & src);
        ~RPN();

        RPN & operator=(const RPN & src);

        static std::stack<int> _mystack;
        static unsigned char ops[4] = {'+', '-', '*', '/'};
        
        static void getOperands(int &lhs, int &rhs);
        static void PushToken(int value);

        static void Operate(unsigned char operator);

        static int computeSum(const int &lhs, const int &rhs);
        static int computeSub(const int &lhs, const int &rhs);
        static int computeMul(const int &lhs, const int &rhs);
        static int computeDiv(const int &lhs, const int &rhs);

};

typedef int (RPN::*m_func) (const int &, const int &);


# endif
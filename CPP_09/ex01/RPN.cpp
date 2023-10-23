/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:11:52 by aandom            #+#    #+#             */
/*   Updated: 2023/10/23 09:11:52 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::_mystack;
unsigned char RPN::ops[] =  {'+', '-', '*', '/'};
m_func  RPN::oprations[4] = {&RPN::computeSum, &RPN::computeSub, &RPN::computeMul, &RPN::computeDiv};


int RPN::computeRPN(const std::string & input) {
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		if (std::isspace(*it))
			continue;
		else if (std::isdigit(*it))
			RPN::PushToken(static_cast<int>(*it - '0'));
		else
			RPN::Operate(static_cast<unsigned char>(*it));
	}
	if (_mystack.size() > 1)
		throw::std::runtime_error("less number of operators");
	int ret = RPN::_mystack.top();
	RPN::_mystack = std::stack<int>();
	return ret;
}

void    RPN::getOperands(int &lhs, int &rhs) {
    if (_mystack.size() < 2)
        throw std::runtime_error("Operation is invalid: stack has less than 2 elements");
    rhs = _mystack.top();
    _mystack.pop();
    lhs = _mystack.top();
    _mystack.pop();
}

void RPN::Operate(unsigned char opesign) {
    // m_func  members[4] = {&RPN::computeSum, &RPN::computeSub, &RPN::computeMul, &RPN::computeDiv};

    int i = 0;
    while (i < 4 && ops[i] != opesign)
        i++;
    if (i < 4){
        int lhs = 0, rhs = 0;
        getOperands(lhs, rhs);
        // int res = (members)[i](lhs, rhs);
        int res = RPN::oprations[i](lhs, rhs);
        PushToken(res);
    }
    else {
        throw std::runtime_error("Invalid operator/operand");
    }
}

void RPN::PushToken(int token) {
	_mystack.push(token);
}

int RPN::computeSum(const int &lhs, const int &rhs) {
    return (lhs + rhs);
}
int RPN::computeSub(const int &lhs, const int &rhs) {
    return (lhs - rhs);
}
int RPN::computeMul(const int &lhs, const int &rhs) {
    return (lhs * rhs);
}
int RPN::computeDiv(const int &lhs, const int &rhs){
    if (rhs == 0)
        throw std::runtime_error("Math error: Attempted to divide by Zero");
    return (lhs / rhs);
}
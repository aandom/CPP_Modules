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

int RPN::computeRPN(const std::string & input) {
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		if (std::isspace(*it))
			continue;
		else if (std::isdigit(*it))
			PushToken(static_cast<int>(*it - '0'));
		else
			Operate(static_cast<unsigned char>(*it));
	}
	if (_mystack.size() > 1)
		throw::std::runtime_error("Operations ended and stack has more than 1 item");
	int ret = _mystack.top();
	_mystack = std::stack<int>();
	return ret;
}

void    RPN::getOperands(int &lhs, int &rhs) {
    rhs = _mystack.top();
    _mystack.pop();
    lhs = -_mystack.top();
    _mystack.pop();
}

void RPN::Operate(unsigned char operator) {
    m_func  members[] = {&RPN::computeSum, &RPN::computeSub, &RPN::computeMul, &RPN::computeDiv};

    int i = 0;
    while (i < 4 && ops[i] != operator)
        i++;
    if (i < 4){
        int lhs = 0, rhs = 0;
        getOperands(lhs, rhs);
        int res = ((*members)[i])(lhs, rhs);
        // int res  =   (members[i])(lhs, rhs);

    }
    else {
        std::cout << "Invalid operator" << std::endl;
    }

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
    return (lhs / rhs);
}
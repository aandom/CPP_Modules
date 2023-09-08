/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 05:08:35 by aandom            #+#    #+#             */
/*   Updated: 2023/08/28 05:08:35 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(void) : _accountIndex(_nbAccounts),
                         _amount(0),
                         _nbDeposits(0),
                         _nbWithdrawals(0) {
    Account::_nbAccounts++;
    return ;
}

Account::Account(int deposit) : _accountIndex(_nbAccounts),
                         _amount(deposit),
                         _nbDeposits(0),
                         _nbWithdrawals(0) {
    Account::_nbAccounts++;
    Account::_totalAmount += _amount;
    _displayTimestamp();
    std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" <<_amount << ";"
				<< "created" << std::endl;
    return ;
}

Account::~Account(void)	{
	Account::_nbAccounts--;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
	return ;
}

int Account::getNbAccounts( void ){
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}
int	Account::getNbDeposits( void ){
    return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ){
    return (Account::_totalNbWithdrawals);
}


void Account::_displayTimestamp( void ){
    std::time_t curtime;
    struct tm *stru_time;

    std::time(&curtime);
    stru_time = std::localtime(&curtime);

    std::cout << "[" << stru_time->tm_year + 1900;
    if (stru_time->tm_mon < 10)
		std::cout << "0";
    std::cout << stru_time->tm_mon;
    if (stru_time->tm_mday < 10)
        std::cout << "0";
    std::cout << stru_time->tm_mday << "_";
    if (stru_time->tm_hour < 10)
        std::cout << "0";
    std::cout << stru_time->tm_hour;
    if (stru_time->tm_min < 10)
        std::cout << "0";
    std::cout << stru_time->tm_min;
    if (stru_time->tm_sec < 10)
        std::cout << "0";
    std::cout << stru_time->tm_sec << "] ";
    return ;

}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "deposit:";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout	<< deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
	return;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:";
    if (withdrawal > this->_amount) {
        std::cout << "refused" << std::endl;
		return (false);
    }
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout	<< withdrawal << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const {
    return(this->_amount);
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout   << "index:"		<< _accountIndex << ";"
                << "amount:"	<<_amount << ";"
                << "deposits:"	<< _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}


void Account::displayAccountsInfos(void)  {
    _displayTimestamp();
    std::cout	<< "accounts:"	<< getNbAccounts() << ";"
				<< "total:"		<< getTotalAmount()	<< ";"
				<< "deposits:"	<< getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}
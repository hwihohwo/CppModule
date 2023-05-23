#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <stdbool.h>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void	is_10_under(int value)
{
	if (value < 10)
		std::cout << 0;
}

Account::Account(int initial_diposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_nbAccounts << ';';
	std::cout << "amount:" << initial_diposit << ';' << "created" << std::endl;
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_diposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_diposit;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->checkAmount() << ';';
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';';
	std::cout << "total:" << Account::getTotalAmount() << ';';
	std::cout << "deposits:" << Account::getNbDeposits() << ';';
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->checkAmount() << ';';
	std::cout << "deposit:" << deposit << ';';
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->checkAmount() << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->checkAmount() << ';';
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << "amount:" << this->checkAmount() << ';';
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->checkAmount() << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	std::cout << '[';
	std::cout << t->tm_year + 1900;
	is_10_under(t->tm_mon + 1);
	std::cout << t->tm_mon + 1;
	is_10_under(t->tm_mday);
	std::cout << t->tm_mday << '_';
	is_10_under(t->tm_hour);
	std::cout << t->tm_hour;
	is_10_under(t->tm_min);
	std::cout << t->tm_min;
	is_10_under(t->tm_sec);
	std::cout << t->tm_sec << ']' << ' ';
}
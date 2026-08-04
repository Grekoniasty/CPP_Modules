#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
	std::time_t time = std::time(NULL);
	std::tm *ltm = std::localtime(&time);
	std::cout << "["
		<< 1900 + ltm->tm_year
		<< (ltm->tm_mon + 1 < 10 ? "0" : "") << ltm->tm_mon + 1
		<< (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
		<< "_"
		<< (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
		<< (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
		<< (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
		<< "] ";


}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {

	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount = initial_deposit + _totalAmount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	_amount = _amount + deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
  	std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	return false;
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(void)
	: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
}

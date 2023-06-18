#include "Account.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int    Account::_nbAccounts = 0;
int    Account::_totalAmount = 0;
int    Account::_totalNbDeposits = 0;
int    Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _nbDeposits(), _nbWithdrawals() {
	_accountIndex = Account::getNbAccounts();
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	Account::_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account() {
	Account::_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << Account::checkAmount() << ";closed" << std::endl;
}

int Account::getNbAccounts() { return (_nbAccounts); }

int Account::getTotalAmount() { return (_totalAmount); }

int Account::getNbDeposits() { return (_totalNbDeposits); }

int Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:"
		 << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	cout << "index:" << _accountIndex << ";p_amount:" << Account::checkAmount() << ";deposit:" << deposit << ";amount:"
		 << Account::checkAmount() + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	if (withdrawal > _amount) {
		cout << "index:" << _accountIndex << ";p_amount:" << Account::checkAmount() << ";withdrawal:refused"
			 << std::endl;
		return (true);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << "index:" << _accountIndex << ";p_amount:" << Account::checkAmount() << ";withdrawal:" << withdrawal
		 << ";amount:" << Account::checkAmount() - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (false);
}

int Account::checkAmount() const {
	return (_amount);
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << Account::checkAmount() << ";deposits:" << _nbDeposits
		 << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	time_t s;

	time(&s);
	cout << "[" << put_time(localtime(&s), "%Y%m%d_%H%M%S") << "] ";
}

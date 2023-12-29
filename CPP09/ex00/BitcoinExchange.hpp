#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>


class BitcoinExchange {

public:
	BitcoinExchange(const char *);
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange &operator=(const BitcoinExchange &);
	~BitcoinExchange();

private:
	BitcoinExchange();
	void loadDatabase();
	void processInput(const char *);
	std::pair<double, float> getPair(std::string line);
	void checkAgainstDatabase(std::pair<double, float>);

	std::map<double, float> _db;

};

#endif
#include "BitcoinExchange.hpp"

std::string timestampToDate(double timestamp) {

	time_t rawtime = (time_t) timestamp;
	struct tm *timeinfo = localtime(&rawtime);
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d", timeinfo);

	return std::string(buffer);
}

void BitcoinExchange::checkAgainstDatabase(std::pair<double, float> pair) {

	std::map<double, float>::iterator it = _db.lower_bound(pair.first);

	if (it != _db.end()) {
		std::cout << timestampToDate(pair.first) << " => " << pair.second
		          << " = " << it->second * pair.second << " " << std::endl;
	}
}

std::pair<double, float> BitcoinExchange::getPair(std::string line) {
	std::istringstream s(line);
	std::string field;

	std::getline(s, field, '|');
	std::tm tm = {};
	std::istringstream ss(field);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		throw std::runtime_error("Error: bad input => " + field);
	double date = std::mktime(&tm);

	std::getline(s, field, '|');
	float value = std::stof(field);
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (value > 1000)
		throw std::runtime_error("Error: too large a number.");

	return std::make_pair(date, value);
}

void BitcoinExchange::processInput(const char *file) {

	std::ifstream data(file);

	if (data.is_open()) {
		std::string line;
		std::getline(data, line);

		while (std::getline(data, line)) {
			try {
				std::pair<double, float> pair = this->getPair(line);
				this->checkAgainstDatabase(pair);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		data.close();
	} else
		throw std::runtime_error("Could not open file");

}

void BitcoinExchange::loadDatabase() {
	std::ifstream data("./data.csv");

	if (data.is_open()) {
		std::string line;
		std::getline(data, line);

		while (std::getline(data, line)) {
			std::istringstream s(line);
			std::string field;

			std::getline(s, field, ',');
			std::tm tm = {};
			std::istringstream ss(field);
			ss >> std::get_time(&tm, "%Y-%m-%d");
			if (ss.fail())
				throw std::runtime_error("Error: bad database element => " + field);
			double date = std::mktime(&tm);

			std::getline(s, field, ',');
			float exchange_rate = std::stof(field);

			_db[date] = exchange_rate;
		}
		data.close();
	} else
		throw std::runtime_error("Could not read database");

}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *file) {

	loadDatabase();
	processInput(file);

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
	if (this != &copy) {
		_db = copy._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
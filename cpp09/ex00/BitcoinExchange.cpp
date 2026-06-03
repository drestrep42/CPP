#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

	BitcoinExchange::readDb();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {

    _exchangeRates = other._exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {

    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::addExchangeRate(const std::string& date, double rate) {

    _exchangeRates[date] = rate;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {

    std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) {
        return it->second;
    }
    return -1;
}

bool BitcoinExchange::validateDate(const std::string& date) {

	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	return true;
}

void BitcoinExchange::printExchangeRates() const {

	for (std::map<std::string, double>::const_iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void BitcoinExchange::readDb() {

	std::ifstream db;
    db.open("data.csv"); 

    if (!db.is_open()) {
        std::cerr << "Error opening db!" << std::endl;
        return ;
    }

	std::string line;
    std::getline(db, line);

    while (std::getline(db, line)) {

		if (line.find(',') == std::string::npos) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }
		line.replace(line.find(','), 1, " ");

        std::istringstream iss(line);
        std::string date;
        double value;
		iss >> date >> value;
        addExchangeRate(date, value);
    }
}

/* double BitcoinExchange::findClosestDate(const std::string& date) {

	std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end()) {
		return (--it)->second;
	} else if (it == _exchangeRates.begin()) {
		return it->second;
	} else {
		std::map<std::string, double>::iterator prev_it = it;
		--prev_it;

		double upper_diff = std::fabs(it->first.compare(date));
		double lower_diff = std::fabs(prev_it->first.compare(date));
		if (upper_diff < lower_diff) {
			return it->second;
		}
		return prev_it->second;
	}
	return -1;
} */

std::map<std::string, double>::iterator BitcoinExchange::findClosestDate(const std::string& date) {

	if (_exchangeRates.find(date) != _exchangeRates.end()) {
		return _exchangeRates.find(date);
	}

	std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end()) {
		--it;
	} else if (it == _exchangeRates.begin()) {
		return it;
	} else {
		std::map<std::string, double>::iterator prev_it = it;
		--prev_it;

		double upper_diff = std::fabs(it->first.compare(date));
		double lower_diff = std::fabs(prev_it->first.compare(date));
		if (upper_diff < lower_diff) {
			return it;
		}
		return prev_it;
	}
	return _exchangeRates.end();
}

void BitcoinExchange::multiplyExchangeRate(const std::string& date, double factor) {

    std::map<std::string, double>::iterator it = findClosestDate(date);
	std::cout << date << " => " << factor << " = " << it->second * factor << std::endl;
}

void BitcoinExchange::run(const std::string& input_file) {

    std::string line;
	std::ifstream input(input_file.c_str());

	if (!input.is_open()) {
		std::cerr << "Error opening input file!" << std::endl;
		return;
	}

	getline(input, line);
    if (line != "date | value") {
        std::cerr << "Invalid database format" << std::endl;
        return;
    }

	while (std::getline(input, line)) {

		if (line.find('|') == std::string::npos) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }
		line.erase(line.find('|'), 1);

        std::istringstream iss(line);
        std::string date;
        long value;
		iss >> date >> value;

		if (!validateDate(date)) {
			std::cerr << "Invalid date in line: " << line << std::endl;
			continue;
		}

		if (value < 0 || value > 1000) {
			std::cerr << "Invalid value: " << value << " - Value must be between 0 and 1000" << std::endl;
			continue;
		}
		multiplyExchangeRate(date, value);
    }
}

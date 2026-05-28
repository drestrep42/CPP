#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& db) {
    std::ifstream file(db.c_str());
    if (!file) {
        std::cerr << "Error opening database file: " << db << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date;
        float rate;

        if (!(iss >> date >> rate)) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }

        addExchangeRate(date, rate);
    }
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

void BitcoinExchange::addExchangeRate(const std::string& date, float rate) {
    _exchangeRates[date] = rate;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end()) {
        return it->second;
    }
    return -1;
}

void BitcoinExchange::run() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string date;
        float value;

        if (!(iss >> date >> value)) {
            std::cerr << "Invalid input format" << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        if (rate != -1) {
            std::cout << "Exchange rate for " << date << ": " << rate * value << std::endl;
        } else {
            std::cerr << "No exchange rate found for " << date << std::endl;
        }
    }
}
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>
#include <fcntl.h>
#include <cmath>

class BitcoinExchange {

	private:
	    std::map<std::string, double> _exchangeRates;

		void readDb();
		void printExchangeRates() const;
		bool validateDate(const std::string& date);
		void multiplyExchangeRate(const std::string& date, double factor);
		//double findClosestDate(const std::string& date);
		std::map<std::string, double>::iterator findClosestDate(const std::string& date);

	public:
	    BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
	    ~BitcoinExchange();

	    void addExchangeRate(const std::string& date, double rate);
	    double getExchangeRate(const std::string& date) const;

		void run(const std::string& input_file);
};

#endif

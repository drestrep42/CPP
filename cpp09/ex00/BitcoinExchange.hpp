#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {

	private:
	    std::map<std::string, float> _exchangeRates;

	public:
	    BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
	    ~BitcoinExchange();

	    void addExchangeRate(const std::string& date, float rate);
	    float getExchangeRate(const std::string& date) const;
};

#endif
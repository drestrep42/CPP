#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>
# include <limits>
# include <cmath>

enum e_type {
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);


	public:
		static void convert(const std::string &literal);
};

void convertSpecial(const std::string &literal);
void convertChar(const std::string &literal);
void convertInt(const std::string &literal);
void convertFloat(const std::string &literal);
void convertDouble(const std::string &literal);

#endif

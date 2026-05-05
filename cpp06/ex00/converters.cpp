#include "ScalarConverter.hpp"

void convertSpecial(const std::string &literal) {
	// Implementation for special conversion (e.g., "nan", "inf")
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void  convertChar(const std::string &literal) {
	// Implementation for char conversion
	const char c = literal[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertInt(const std::string &literal) {
	// Implementation for int conversion
	int value = std::atol(literal.c_str());
	std::cout << "char: ";
	if (std::isprint(value)) {
		std::cout << "'" << static_cast<char>(value) << "'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertFloat(const std::string &literal) {
	// Implementation for float conversion
	float value = std::atof(literal.c_str());
	std::cout << "char: ";
	if (std::isprint(static_cast<int>(value))) {
		std::cout << "'" << static_cast<char>(value) << "'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertDouble(const std::string &literal) {
	// Implementation for double conversion
	std::cout << "char: ";
	if (std::isprint(static_cast<int>(std::atof(literal.c_str())))) {
		std::cout << "'" << static_cast<char>(std::atof(literal.c_str())) << "'";
	} else {
		std::cout << "Non displayable";
	}
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(std::atol(literal.c_str())) << std::endl;
	std::cout << "float: " << static_cast<float>(std::atof(literal.c_str())) << "f" << std::endl;
	double value = std::atof(literal.c_str());
	std::cout << "double: " << value << std::endl;
	std::cout << "literal: " << literal << std::endl;
}

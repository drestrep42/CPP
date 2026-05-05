#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& literal) {
	(void)literal;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& literal) {
	(void)literal;
	return *this;
}

e_type	getType(const std::string &literal) {
	// Implementation to determine the type of the literal
	if (literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "+inff" || literal == "-inff") {
		return SPECIAL;
	} else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		return CHAR;
	} else if (literal.find('.') == std::string::npos) {
		for (size_t i = 0; i < literal.length(); ++i) {
			if (!std::isdigit(literal[i]) && !(i == 0 && literal[i] == '-')) {
				return UNKNOWN;
			}
		}
		return INT;
	} else if (literal.find('.') != std::string::npos) {
		size_t dotPos = literal.find('.');
		if (dotPos == 0 || dotPos == literal.length() - 1) {
			return UNKNOWN;
		}
		for (size_t i = 0; i < literal.length(); ++i) {
			if (literal[i] == 'f' && i == literal.length() - 1) {
				continue;
			}
			if (!std::isdigit(literal[i]) && literal[i] != '.' && !(i == 0 && literal[i] == '-')) {
				return UNKNOWN;
			}
		}
		return DOUBLE;
	} else if (literal.find('.') != std::string::npos && literal.find('f') == literal.length() - 1) {
		size_t dotPos = literal.find('.');
		if (dotPos == 0 || dotPos == literal.length() - 2) {
			return UNKNOWN;
		}
		for (size_t i = 0; i < literal.length() - 1; ++i) {
			if (!std::isdigit(literal[i]) && literal[i] != '.' && !(i == 0 && literal[i] == '-')) {
				return UNKNOWN;
			}
		}
		return FLOAT;
	}
	return UNKNOWN;
}

void ScalarConverter::convert(const std::string &literal) {

	e_type type = getType(literal);
	switch (type) {
		case SPECIAL:
			convertSpecial(literal);
			break;
		case CHAR:
			convertChar(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
			break;
		case UNKNOWN:
			break;
	}
}

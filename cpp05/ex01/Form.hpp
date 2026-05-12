#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade2sign;
		const int			_grade2execute;

	public:
		Form();
		Form(const std::string name, bool sign, \
			const int grade2sign, const int grade2execute);

		~Form();
		
		Form(const Form& copy);
		Form&	operator=(const Form& copy);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGrade2Sign() const;	
		int					getGrade2Execute() const;

		bool				beSigned(Bureaucrat &bureaucrat);

		
		class GradeTooHighException : public std::exception  {
			public:
				virtual const char*	what() const throw() {
					return ("The highest possible grade is 1!");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("The lowest possible grade is 150!");
				}
		};

		class BureaucratTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("the bureaucrat's grade is too low to sign the form!");
				}
		};

		class FormShouldBeUnsignedException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("The form should be unsigned!");
				}
		};
};


std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
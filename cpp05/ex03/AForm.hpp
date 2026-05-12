#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade2sign;
		const int			_grade2execute;

	public:
		AForm();
		AForm(const std::string name, bool sign, \
			const int grade2sign, const int grade2execute);

		virtual ~AForm();
		
		AForm(const AForm& copy);
		AForm&	operator=(const AForm& copy);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGrade2Sign() const;	
		int					getGrade2Execute() const;

		bool				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const& executor) const = 0;

		
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

		class BureaucratTooLowToSignException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("the bureaucrat's grade is too low to sign the form!");
				}
		};

		class BureaucratTooLowToExecuteException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("the bureaucrat's grade is too low to execute the form!");
				}
		};

		class FormShouldBeUnsignedException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("the form should be unsigned!");
				}
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("the form is not signed!");
				}
		};
};


std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
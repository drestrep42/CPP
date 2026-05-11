#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);

		~Bureaucrat();
		
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&	operator=(const Bureaucrat& copy);

		const std::string	getName() const;
		int					getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(Form &form);

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
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif

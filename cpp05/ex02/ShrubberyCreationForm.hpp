#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

		void writeTrees(const std::string& filename) const;
		virtual void execute(Bureaucrat const& executor) const;
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif

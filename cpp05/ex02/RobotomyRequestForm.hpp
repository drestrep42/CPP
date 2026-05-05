#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

	void robotomize() const;
	virtual void execute(Bureaucrat const& executor) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif

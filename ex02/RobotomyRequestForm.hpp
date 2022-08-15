#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

	RobotomyRequestForm(std::string target);
	void	action() const;
private:
	std::string	target_;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */

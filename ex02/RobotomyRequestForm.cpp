#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
: Form("RobotomyRequestForm", 72, 45)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: Form("RobotomyRequestForm", 72, 45)
{
	*this = other;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

void	RobotomyRequestForm::action() const
{
	std::cout << "whee!!!!!!!!" << std::endl;
	std::srand(time(nullptr));
	int	random_num = rand();
	if (random_num % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "the robotomy of " << this->_target << " failed..." << std::endl;
}
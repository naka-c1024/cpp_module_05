#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	this->arr[0] = "robotomy request";
	this->arr[1] = "presidential request";
	this->arr[2] = "shrubbery request";
	this->arr[3] = "something else";
}
Intern::~Intern()
{
}
Intern::Intern(const Intern &other)
{
	*this = other;
}
Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Form	*Intern::makeForm(std::string form_name, std::string target)
{
	std::size_t	i = 0;
	while (form_name != this->arr[i] && i < 3)
		i++;

	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << form_name << std::endl;
		return new RobotomyRequestForm(target);
		break;
	case 1:
		std::cout << "Intern creates " << form_name << std::endl;
		return new PresidentialPardonForm(target);
		break;
	case 2:
		std::cout << "Intern creates " << form_name << std::endl;
		return new ShrubberyCreationForm(target);
		break;
	default:
		std::cout << "This form name doesn't exist." << std::endl;
		std::cout << "You can use form name:" << std::endl;
		std::cout << "robotomy request" << std::endl;
		std::cout << "presidential request" << std::endl;
		std::cout << "shrubbery request" << std::endl;
		return nullptr;
		break;
	}
}

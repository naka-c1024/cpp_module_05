#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);

	Form	*makeForm(std::string form_name, std::string target);
private:
	std::string	arr_[4];
};

#endif /* INTERN_HPP */

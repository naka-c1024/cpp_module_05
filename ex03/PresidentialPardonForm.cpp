#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm", 25, 5)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: Form("PresidentialPardonForm", 25, 5)
{
	*this = other;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5), target_(target)
{
}

void	PresidentialPardonForm::action() const
{
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
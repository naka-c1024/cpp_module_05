#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

	PresidentialPardonForm(std::string target);
	void	action() const;
private:
	std::string	target_;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

void	ShrubberyCreationFormTest(void)
{
	try
	{
		ShrubberyCreationForm	shru("home");
		std::cout << shru << std::endl;
		Bureaucrat	bure("NIWASHI", 137);
		std::cout << bure << std::endl;
		bure.signForm(shru);
		bure.executeForm(shru);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	RobotomyRequestFormTest(void)
{
	try
	{
		RobotomyRequestForm	rob("Human");
		std::cout << rob << std::endl;
		Bureaucrat	bure("Doctor", 45);
		std::cout << bure << std::endl;
		bure.signForm(rob);
		bure.executeForm(rob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	PresidentialPardonFormTest(void)
{
	try
	{
		PresidentialPardonForm	pre("Criminal");
		std::cout << pre << std::endl;
		Bureaucrat	bure("obama", 5);
		std::cout << bure << std::endl;
		bure.signForm(pre);
		bure.executeForm(pre);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	std::cout << "---- ShrubberyCreationFormTest ----" << std::endl;
	ShrubberyCreationFormTest();
	std::cout << std::endl;
	std::cout << "---- RobotomyRequestFormTest ----" << std::endl;
	RobotomyRequestFormTest();
	std::cout << std::endl;
	std::cout << "---- PresidentialPardonFormTest ----" << std::endl;
	PresidentialPardonFormTest();
	return 0;
}

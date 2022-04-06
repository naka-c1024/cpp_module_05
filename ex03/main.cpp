#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

void	ShrubberyCreationFormTest(void)
{
	Intern someRandomIntern;
	Form* scf;
	scf = someRandomIntern.makeForm("shrubbery request", "Bender");
	std::cout << *scf << std::endl;
	try
	{
		Bureaucrat	bure("NIWASHI", 137); // gradeを変えて色々試す146,145,138,137
		std::cout << bure << std::endl;
		bure.signForm(*scf);
		(*scf).execute(bure);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete scf;
}

void	RobotomyRequestFormTest(void)
{
	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;
	try
	{
		Bureaucrat	bure("Doctor", 45); // gradeを変えて色々試す73,72,46,45
		std::cout << bure << std::endl;
		bure.signForm(*rrf);
		(*rrf).execute(bure);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete rrf;
}

void	PresidentialPardonFormTest(void)
{
	Intern someRandomIntern;
	Form* ppf;
	ppf = someRandomIntern.makeForm("presidential request", "Bender");
	std::cout << *ppf << std::endl;
	try
	{
		Bureaucrat	bure("obama", 5); // gradeを変えて色々試す26,25,6,5
		std::cout << bure << std::endl;
		bure.signForm(*ppf);
		(*ppf).execute(bure);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete ppf;
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
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("invalid argument", "Bender");
	}
	return 0;
}
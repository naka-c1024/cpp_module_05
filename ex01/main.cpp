#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	normal_test(void)
{
	std::cout << "---- normal test ----" << std::endl;
	try
	{
		Form obj("normal_test", 42, 42);
		std::cout << obj << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	exception_constructor_test(void)
{
	std::cout << "---- exception constructor test" << std::endl;
	try
	{
		Form obj("gradeRequireSign_high", -100, 42);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form obj("gradeRequireSign_low", 200, 42);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form obj("gradeRequireExecute_high", 42, -42);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form obj("gradeRequireExecute_low", 42, 500);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	signForm_and_beSigned_test(void)
{
	std::cout << "---- signForm_and_beSigned_test ----" << std::endl;
	try
	{
		Bureaucrat	bure("Tarou", 42);
		std::cout << bure << std::endl;
		Form		form("paper", 40, 100);
		std::cout << form << std::endl;
		form.beSigned(bure);
		bure.incrementGrade();
		bure.incrementGrade();
		std::cout << bure << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat	bure("Tarou", 42);
		std::cout << bure << std::endl;
		Form		form("paper", 40, 100);
		std::cout << form << std::endl;
		bure.incrementGrade();
		bure.incrementGrade();
		std::cout << bure << std::endl;
		bure.signForm(form);
		std::cout << form << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	normal_test();
	std::cout << std::endl;
	exception_constructor_test();
	std::cout << std::endl;
	signForm_and_beSigned_test();
	return 0;
}

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat obj("decrement_test", 42);
		std::cout << "before: " << obj << std::endl;
		obj.decrementGrade();
		std::cout << "after" << obj << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat obj("increment_test", 42);
		std::cout << "before" << obj << std::endl;
		obj.incrementGrade();
		std::cout << "after" << obj << std::endl;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat obj("constructor_high_exception_test", 0);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat obj("constructor_low_exception_test", 151);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat obj("high_exception_test", 1);
		std::cout << obj << std::endl;
		obj.incrementGrade();
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat obj("low_exception_test", 150);
		std::cout << obj << std::endl;
		obj.decrementGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

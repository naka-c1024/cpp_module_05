#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat: invalid defalt constructor called" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
		// this->_name = other.getName(); // constだからconstructor以外で変更不可
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name), _grade(grade) {}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return out;
}

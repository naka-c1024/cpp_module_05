#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat: invalid defalt constructor called!!" << std::endl;
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
		this->grade_ = other.getGrade();
		// this->name_ = other.getName(); // constだからconstructor以外で変更不可
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name_(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ = grade;
}

std::string	Bureaucrat::getName() const
{
	return (this->name_);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade_ >= 2)
		(this->grade_)--; // 等級を上げるからグレードを下げる
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade_ <= 149)
		(this->grade_)++;
	else
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout << this->getName() << "couldn't sign " << form.getName() << " because " << "already signed." << std::endl;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << "couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("This grade is too HIGH above the grade range.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("This grade is too LOW above the grade range.");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}

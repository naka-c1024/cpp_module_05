#include "Form.hpp"
#include <iostream>

Form::Form():_name("unknown"), _isSigned(false), _gradeRequireSign(42), _gradeRequireExecute(42)
{
	std::cout << "Form: Invalid defalt constructor called!!" << std::endl;
}
Form::~Form()
{
}
Form::Form(const Form &other): _name(other._name), _gradeRequireSign(other._gradeRequireSign), _gradeRequireExecute(other._gradeRequireExecute)
{
	*this = other;
}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string	Form::getName() const
{
	return (this->_name);
}
bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}
int		Form::getGradeRequireSign() const
{
	return (this->_gradeRequireSign);
}
int		Form::getGradeRequireExecute() const
{
	return (this->_gradeRequireExecute);
}

Form::Form(std::string name, int gradeRequireSign, int gradeRequireExecute)
:_name(name), _gradeRequireSign(gradeRequireSign), _gradeRequireExecute(gradeRequireExecute)
{
	_isSigned = false;
	if (gradeRequireSign < 1 || gradeRequireExecute < 1)
	{
		throw Form::GradeTooHighException("This grade is too HIGH above the grade range.");
	}
	else if (gradeRequireSign > 150 || gradeRequireExecute > 150)
	{
		throw Form::GradeTooLowException("This grade is too LOW above the grade range.");
	}
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeRequireSign())
	{
		throw Form::GradeTooLowException("this bureaucrat's grade is NOT high enough.");
	}
	this->_isSigned = true;
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cout << "This form is NOT signed." << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getGradeRequireExecute())
		throw Form::GradeTooLowException("This grade of the bureaucrat attempting to execute the form is LOW.");
	this->action();
}

Form::GradeTooHighException::GradeTooHighException(const std::string err_msg): std::out_of_range(err_msg) {}
Form::GradeTooLowException::GradeTooLowException(const std::string err_msg): std::out_of_range(err_msg) {}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	out << "-- all the form's informations --" << std::endl;
	out << "Name: " << rhs.getName() << std::endl;
	out << "A indicating whether it is signed: ";
	if (rhs.getIsSigned() == true)
		out << "true" << std::endl;
	else
		out << "false" << std::endl;
	out << "A grade required to sign it: " << rhs.getGradeRequireSign() << std::endl;
	out << "A grade required to execute it: " << rhs.getGradeRequireExecute();
	return out;
}
#include "Form.hpp"

Form::Form():_name("unknown"), _isSigned(false), _gradeRequireSign(42), _gradeRequireExecute(42)
{
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

const char *Form::GradeTooHighException::what() const throw()
{
	return ("This grade is too HIGH above the grade range.");
}
const char *Form::GradeTooLowException::what() const throw()
{
	return ("This grade is too LOW above the grade range.");
}

std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	// out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}
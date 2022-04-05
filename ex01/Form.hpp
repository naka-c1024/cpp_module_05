#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form
{
public:
	Form();
	~Form();
	Form(Form const &other);
	Form &operator=(Form const &other);

	// Nested classes
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw(); // オーバーライド
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw(); // オーバーライド
	};

private:
	const std::string	_name;
	bool	_isSigned;
	const int	_gradeRequireSign;
	const int	_gradeRequireExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif /* FORM_HPP */

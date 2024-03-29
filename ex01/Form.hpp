#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Bureaucrat; // 相互参照するための前方宣言

class Form
{
public:
	Form();
	~Form();
	Form(Form const &other);
	Form &operator=(Form const &other);

	Form(std::string name, int gradeRequireSign, int gradeRequireExecute);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeRequireSign() const;
	int			getGradeRequireExecute() const;

	void	beSigned(Bureaucrat bureaucrat);

	// Nested classes
	class GradeTooHighException : public std::out_of_range
	{
	public:
		GradeTooHighException(const std::string err_msg);
	};
	class GradeTooLowException : public std::out_of_range
	{
	public:
		GradeTooLowException(const std::string err_msg);
	};

private:
	const std::string	name_;
	bool				isSigned_;
	const int	gradeRequireSign_; // ranges from 1 to 150
	const int	gradeRequireExecute_; // ranges from 1 to 150
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif /* FORM_HPP */

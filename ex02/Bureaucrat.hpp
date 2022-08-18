#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);

	Bureaucrat(std::string name, int grade);

	std::string	getName() const;
	int			getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &form);

	void	executeForm(Form const & form);

	// Nested classes
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	const std::string	name_;
	int					grade_; // ranges from 1 to 150
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif /* BUREAUCRAT_HPP */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

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
	int					_grade; // ranges from 1 to 150
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif /* BUREAUCRAT_HPP */

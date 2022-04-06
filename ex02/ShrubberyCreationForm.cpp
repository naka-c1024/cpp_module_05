#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
: Form("ShrubberyCreationForm", 145, 137)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: Form("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

void	ShrubberyCreationForm::action() const
{
	// treeコマンドはmacに入っていないのでアスキーアートにする
	std::ofstream ofs(this->_target + "_shrubbery");
	if (ofs.fail())
	{
		std::cerr << "Failed to open file." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	ofs << "              v .   ._, |_  .," << std::endl;
	ofs << "           `-._\\/  .  \\ /    |/_" << std::endl;
	ofs << "               \\  _\\, y | \\//" << std::endl;
	ofs << "         _\\_.___\\, \\/ -.\\||" << std::endl;
	ofs << "           `7-,--.`._||  / / ," << std::endl;
	ofs << "           /'     `-. `./ / |/_.'" << std::endl;
	ofs << "                     |    |//" << std::endl;
	ofs << "                     |_    /" << std::endl;
	ofs << "                     |-   |" << std::endl;
	ofs << "                     |   =|" << std::endl;
	ofs << "                     |    |" << std::endl;
	ofs << "--------------------/ ,  . \\--------._" << std::endl;
}

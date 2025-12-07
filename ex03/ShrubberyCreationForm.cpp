/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:13:03 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 17:57:24 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery", SHRUBBERY_GRADE_TO_SIGN, SHRUBBERY_GRADE_TO_EXECUTE),
	_target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other),
	_target(other._target) {};

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator = (other);
	// this->_target = other._target;
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	outFile;
	std::string		fileName = this->_target + "_shrubbery";

	outFile.open(fileName);
	if (!outFile)
	{
		std::cerr << COL_R << "Error: Could not create file " << fileName << COL_X << std::endl;
		return ;
	};
	outFile << "       _-_   \n";
	outFile << "    /~~   ~~\\\n";
	outFile << " /~~         ~~\\\n";
	outFile << "{         /     }\n";
	outFile << " \\     \\    _  /\n";
	outFile << "  \\~~~\\\\ //~~~/\n";
	outFile << "       | |\n";
	outFile << "       / \\";
	outFile.close();
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/07 01:45:42 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &other){(void)other;};

Intern &Intern::operator = (const Intern &other){(void)other; return (*this);};

Intern::~Intern(){}

const char* Intern::FormNotFoundException::what() const noexcept
{
	return ("Intern has tried to create a non-existent form.");
}

AForm* Intern::makeForm(const std::string formName, const std::string target) const
{
	int	formType = -1;

	std::string	formNames[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			formType = i;
	}
	if (formType != -1)
		std::cout << "Intern creates " << formName << " form." << std::endl;
	switch (formType)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
	}
	throw FormNotFoundException();
}

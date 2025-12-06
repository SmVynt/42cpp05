/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:13:03 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 18:44:28 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon", PRESIDENTIALPARDON_GRADE_TO_SIGN, PRESIDENTIALPARDON_GRADE_TO_EXECUTE),
	_target(target)
{
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other),
	_target(other._target)
{
};

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator = (other);
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm(){};

void	PresidentialPardonForm::executeAction() const
{
	std::cout << COL_G << this->_target << " has been pardoned by Zaphod Beeblebrox." << COL_X << std::endl;
}


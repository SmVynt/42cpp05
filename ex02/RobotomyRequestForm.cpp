/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:13:03 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 18:38:48 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Robotomy", ROBOTOMY_GRADE_TO_SIGN, ROBOTOMY_GRADE_TO_EXECUTE),
	_target(target)
{
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other),
	_target(other._target)
{
};

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	AForm::operator = (other);
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm(){};

void	RobotomyRequestForm::executeAction() const
{
	std::cout << COL_Y << "***Drilling noizes***" << COL_X << std::endl;
	if (rand() % 2)
		std::cout << COL_G << this->_target << " has been robotomized successfully!" << COL_X << std::endl;
	else
		std::cout << COL_R << "Robotomy failed on " << this->_target << COL_X << std::endl;
}


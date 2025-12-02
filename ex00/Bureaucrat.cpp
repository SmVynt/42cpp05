/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/02 12:01:56 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	try {
		if (grade < GRADE_HIGHEST)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > GRADE_LOWEST)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = grade;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{

};
Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
};

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " is destroyed." << std::endl;
}

std::string	Bureaucrat::getName() const {return (this->_name);};

int			Bureaucrat::getGrade() const {return (this->_grade);};

void Bureaucrat::GradeTooHighException()
{
	std::cout << "Grade is too high!" << std::endl;
}
void Bureaucrat::GradeTooLowException()
{
	std::cout << "Grade is too low!" << std::endl;
}

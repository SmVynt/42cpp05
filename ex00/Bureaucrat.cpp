/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/02 18:29:50 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if (grade < GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){};

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

void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}
std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

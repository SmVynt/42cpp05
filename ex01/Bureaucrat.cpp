/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:45 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 00:42:03 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
	if (grade < GRADE_HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > GRADE_LOWEST)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){};

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
};

Bureaucrat::~Bureaucrat(){}

std::string	Bureaucrat::getName() const {return (this->_name);};

int		Bureaucrat::getGrade() const {return (this->_grade);};

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

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << COL_G << this->_name << " signed " << form.getName() << COL_X << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << COL_R << this->_name << " couldn't sign " << form.getName() \
		<< " because " << e.what() << COL_X << std::endl;
	}
}

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << COL_Y << bureaucrat.getName() << COL_X << ", bureaucrat grade " \
	<< COL_Y << bureaucrat.getGrade() << COL_X << ".";
	return out;
}

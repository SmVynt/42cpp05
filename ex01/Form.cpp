/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:13:03 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 00:37:32 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	if (gradeToSign < GRADE_HIGHEST || gradeToExecute < GRADE_HIGHEST)
		throw Form::GradeTooHighException();
	if (gradeToSign > GRADE_LOWEST || gradeToExecute > GRADE_LOWEST)
		throw Form::GradeTooLowException();
};
Form::Form(const Form &other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_signed(other._signed)
{
};

Form &Form::operator = (const Form &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
};

Form::~Form(){};

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

std::string	Form::getName() const {return this->_name;};
int			Form::getGradeToSign() const {return this->_gradeToSign;};
int			Form::getGradeToExecute() const {return this->_gradeToExecute;};
bool		Form::isSigned() const {return this->_signed;};
void		Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
};

std::ostream &operator << (std::ostream &out, const Form &form)
{
	out << "Form: " << COL_Y << form.getName() << COL_X << "\n" \
	<< "Grade to sign: " << COL_Y << form.getGradeToSign() << COL_X << "\n" \
	<< "Grade to execute: " << COL_Y << form.getGradeToExecute() << COL_X << "\n" \
	<< "Form is ";
	if (form.isSigned())
		out << COL_G << "signed" << COL_X << ".";
	else
		out << COL_R << "not signed" << COL_X << ".";
	return out;
}

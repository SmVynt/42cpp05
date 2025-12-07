/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:13:03 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 18:35:56 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	if (gradeToSign < GRADE_HIGHEST || gradeToExecute < GRADE_HIGHEST)
		throw AForm::GradeTooHighException();
	if (gradeToSign > GRADE_LOWEST || gradeToExecute > GRADE_LOWEST)
		throw AForm::GradeTooLowException();
};
AForm::AForm(const AForm &other) :
	_name(other._name),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute),
	_signed(other._signed)
{
};

AForm &AForm::operator = (const AForm &other)
{
	if (this == &other)
		return *this;
	this->_signed = other._signed;
	return *this;
};

AForm::~AForm(){};

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

const char *AForm::FormIsNotSignedException::what() const noexcept
{
	return ("Form is not signed!");
}

std::string	AForm::getName() const {return this->_name;};
int			AForm::getGradeToSign() const {return this->_gradeToSign;};
int			AForm::getGradeToExecute() const {return this->_gradeToExecute;};
bool		AForm::isSigned() const {return this->_signed;};
void		AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
};

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!this->isSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	this->executeAction();
}

std::ostream &operator << (std::ostream &out, const AForm &form)
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

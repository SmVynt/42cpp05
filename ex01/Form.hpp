/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:13:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 00:28:16 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_signed;
	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator = (const Form &other);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const noexcept;
		};

		std::string getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		isSigned() const;
		void		beSigned(const Bureaucrat &bureaucrat);

};

std::ostream &operator << (std::ostream &out, const Form &form);

#endif

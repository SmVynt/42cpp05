/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:50 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 00:24:16 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define COL_R	"\033[31m"
# define COL_Y	"\033[33m"
# define COL_G	"\033[32m"
# define COL_B	"\033[34m"
# define COL_X	"\033[0m"

# define GRADE_LOWEST	150
# define GRADE_HIGHEST	1

class Form;

class Bureaucrat
{
	private:
		const std::string		_name;
		int						_grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator = (const Bureaucrat &other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};

		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form);
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif

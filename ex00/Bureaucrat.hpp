/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:50 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/02 18:34:55 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define COL_R	"\033[31m"
# define COL_Y	"\033[33m"
# define COL_B	"\033[34m"
# define COL_X	"\033[0m"

# define GRADE_LOWEST	150
# define GRADE_HIGHEST	1

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
			const char *what() const noexcept
				{return ("Grade is too high!");}
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const noexcept
				{return ("Grade is too low!");}
		};

		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &bureaucrat);

#endif

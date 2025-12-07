/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 01:04:50 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/07 01:43:34 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator = (const Intern &other);
		~Intern();

		AForm* makeForm(const std::string formName, const std::string target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const noexcept;
		};
};

#endif

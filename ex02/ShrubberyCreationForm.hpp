/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:18:51 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 18:18:52 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"

# define SHRUBBERY_GRADE_TO_SIGN	145
# define SHRUBBERY_GRADE_TO_EXECUTE	137

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		void	executeAction() const;
};

#endif

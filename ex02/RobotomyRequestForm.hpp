/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:18:51 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 18:21:35 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"

# define ROBOTOMY_GRADE_TO_SIGN	72
# define ROBOTOMY_GRADE_TO_EXECUTE	45

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void	executeAction() const;
};

#endif

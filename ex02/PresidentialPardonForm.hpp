/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:18:51 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 18:43:54 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"

# define PRESIDENTIALPARDON_GRADE_TO_SIGN		25
# define PRESIDENTIALPARDON_GRADE_TO_EXECUTE	5

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void	executeAction() const override;
};

#endif

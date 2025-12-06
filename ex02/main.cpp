/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:32 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/06 13:37:37 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	srand(time(NULL));

	try
	{
		Bureaucrat alice("Alice", 40);
		ShrubberyCreationForm form1("Form");
		std::cout << alice << std::endl;
		std::cout << form1 << std::endl;
		alice.executeForm(form1);
		alice.signForm(form1);
		std::cout << form1 << std::endl;
		alice.executeForm(form1);
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}
	std::cout << "...................." << std::endl;


	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm form1("Bob");
		std::cout << alice << std::endl;
		std::cout << form1 << std::endl;
		alice.executeForm(form1);
		alice.signForm(form1);
		std::cout << form1 << std::endl;
		alice.executeForm(form1);
		alice.executeForm(form1);
		alice.executeForm(form1);
		alice.executeForm(form1);
		alice.executeForm(form1);
		alice.executeForm(form1);
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}
	std::cout << "...................." << std::endl;


	try
	{
		Bureaucrat alice("Alice", 40);
		Bureaucrat zaphod("Zaphod", 3);
		PresidentialPardonForm form1("Alan");
		std::cout << alice << std::endl;
		std::cout << zaphod << std::endl;
		std::cout << form1 << std::endl;
		alice.signForm(form1);
		zaphod.signForm(form1);
		std::cout << form1 << std::endl;
		alice.executeForm(form1);
		zaphod.executeForm(form1);
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}
	std::cout << "...................." << std::endl;
	return (0);
}

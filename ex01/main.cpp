/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:32 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/05 00:36:40 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat alice("Alice", 40);
		Form form1("Form 1", 50, 30);
		std::cout << alice << std::endl;
		std::cout << form1 << std::endl;
		alice.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}
	std::cout << "...................." << std::endl;

	try
	{
		Bureaucrat bob("Bob", 100);
		Form form2("Form 2", 50, 30);
		std::cout << bob << std::endl;
		std::cout << form2 << std::endl;
		bob.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}
	std::cout << "...................." << std::endl;

	try
	{
		Form invalidForm("0 Form", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}
	std::cout << "...................." << std::endl;

	try
	{
		Form invalidForm2("151 Form", 50, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}

	return (0);
}

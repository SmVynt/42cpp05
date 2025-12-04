/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:51:32 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/04 01:41:07 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	alice("Alice", 42);
		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << "++: " << alice << std::endl;

		alice.decrementGrade();
		std::cout << "--: " << alice << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}

	try
	{
		Bureaucrat	bob("Bob", 151);
		std::cout << bob << std::endl;
		Bureaucrat	sam("Sam", 152);
		std::cout << sam << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}

	try
	{
		Bureaucrat	charlie("Charlie", 0);
		std::cout << charlie << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}

	try
	{
		Bureaucrat	dave("Dave", 1);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << dave << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}

	try
	{
		Bureaucrat	eve("Eve", 150);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << eve << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << COL_R << "Exception: " << e.what() << COL_X << std::endl;
	}

	return (0);
}

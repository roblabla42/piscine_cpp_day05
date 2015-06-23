/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:36:03 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/22 20:41:44 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	Bureaucrat b1;
	Bureaucrat b2("test", 125);


	std::cout << b1 << std::endl << b2 << std::endl;
	try
	{
		Bureaucrat b3("test2", 185);
		std::cout << b3 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("test3", 0);
		std::cout << b4 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat b5("Test", 1);
	Bureaucrat b6("Last Test", 150);
	try
	{
		b5.incGrade();
		std::cout << b5 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b6.decGrade();
		std::cout << b6 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Form f("Test", 149, 140);
	b6.signForm(f);
	b5.signForm(f);
}

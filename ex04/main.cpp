/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:36:03 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 16:29:36 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(0));
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

	PresidentialPardonForm f1("Test");
	try {
	b6.signForm(f1);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	b5.signForm(f1);
	try {
	b6.executeForm(f1);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	b5.executeForm(f1);

	ShrubberyCreationForm f2("Test");
	try {
	b6.signForm(f2);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	b5.signForm(f2);
	try {
	b6.executeForm(f2);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	b5.executeForm(f2);

	RobotomyRequestForm f3("Test");
	try {
	b6.signForm(f3);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	b5.signForm(f3);
	try {
	b6.executeForm(f3);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	b5.executeForm(f3);

	Intern	i;
	try {
		i.makeForm("request", "target");
	} catch (std::exception &e)
	{
		std::cout << "form does not exist" << std::endl;
	}
	try
	{
	b6.signForm(*i.makeForm("robotomy request", "me"));
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	OfficeBlock b(&i, &b5, &b5);
	b.doBureaucracy("robotomy request", "me");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:23:52 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 15:10:31 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Form	*createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*createPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	Form*(*fns[])(std::string target) = {
		createShrubbery,
		createRobotomy,
		createPardon,
	};
	size_t i = 0;
	while (i < sizeof(names) / sizeof(names[0]) && names[i] != name)
		i++;
	if (i == sizeof(names) / sizeof(names[0]))
	{
		std::cout << "WTF PANIC IDUNNOHOWTODOZIS" << std::endl;
		return (NULL);
	}
	else
	{
		std::cout << "Intern creates " << name << std::endl;
		return (fns[i](target));
	}
}

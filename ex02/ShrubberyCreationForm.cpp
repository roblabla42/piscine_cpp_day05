/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 23:38:37 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:10:03 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137), target("target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
	Form("ShrubberyCreationForm", 145, 137), target(src.target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	this->target = rhs.target;
	return (*this);
}

void					ShrubberyCreationForm::action() const
{
	std::ofstream o((target + "_shrubbery").c_str());

	o << "ASCII trees" << std::endl;
}

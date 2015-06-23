/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:10:13 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:11:02 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", 145, 137), target("target")
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
	Form("PresidentialPardonForm", 145, 137), target(src.target)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", 145, 137), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	this->target = rhs.target;
	return (*this);
}

void					PresidentialPardonForm::action() const
{
	std::cout << target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

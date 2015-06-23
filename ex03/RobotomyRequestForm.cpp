/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:05:22 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:08:57 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", 72, 45), target("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
	Form("RobotomyRequestForm", 72, 45), target(src.target)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	this->target = rhs.target;
	return (*this);
}

void					RobotomyRequestForm::action() const
{
	std::cout << "some drilling noises" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized." << std::endl;
	else
		std::cout << target << " has not been robotomoized." << std::endl;
}

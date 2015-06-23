/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 16:15:54 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 16:20:45 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(Intern *i, Bureaucrat *s, Bureaucrat *e) :
	i(i), s(s), e(e)
{

}

OfficeBlock::~OfficeBlock()
{
}

void	OfficeBlock::setIntern(Intern *i)
{
	this->i = i;
}

void	OfficeBlock::setSigner(Bureaucrat *i)
{
	this->s = i;
}


void	OfficeBlock::setExecutor(Bureaucrat *i)
{
	this->e = i;
}

void	OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	if (i == NULL || s == NULL || e == NULL)
		return;
	Form *f = i->makeForm(name, target);
	s->signForm(*f);
	e->executeForm(*f);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 16:01:13 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 16:25:10 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
	Intern *i;
	Bureaucrat *s;
	Bureaucrat *e;
	OfficeBlock();
	OfficeBlock(OfficeBlock const & src);

	OfficeBlock		&operator=(OfficeBlock const &rhs);

public:
	OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
	virtual ~OfficeBlock();

	void setIntern(Intern *i);
	void setSigner(Bureaucrat *b);
	void setExecutor(Bureaucrat *b);
	void doBureaucracy(std::string name, std::string target);
};

#endif

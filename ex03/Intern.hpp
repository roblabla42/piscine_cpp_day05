/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:22:23 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:57:09 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include <string>

class Intern
{
public:
	Intern();
	Intern(Intern const & src);
	virtual ~Intern();

	Intern		&operator=(Intern const &rhs);

	Form		*makeForm(std::string name, std::string target) const;
};

#endif

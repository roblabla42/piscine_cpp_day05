/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 20:42:23 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:12:33 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	std::string target;

	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & src);

	ShrubberyCreationForm		&operator=(ShrubberyCreationForm const &rhs);

protected:
	void						action() const;
public:
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
};

#endif

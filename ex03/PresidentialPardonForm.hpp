/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:09:07 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:12:20 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	std::string target;

	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & src);

	PresidentialPardonForm		&operator=(PresidentialPardonForm const &rhs);

protected:
	void						action() const;
public:
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();
};

#endif

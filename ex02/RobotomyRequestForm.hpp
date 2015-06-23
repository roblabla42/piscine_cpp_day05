/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 13:31:03 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 14:15:53 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	std::string	target;

	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & src);

	RobotomyRequestForm		&operator=(RobotomyRequestForm const &rhs);

protected:
	void					action() const;
public:
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();
};

#endif

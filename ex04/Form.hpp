/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 16:40:01 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/22 23:42:03 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
//#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	std::string const	name;
	bool				sign;
	int const			gradeSign;
	int const			gradeExec;

	Form				&operator=(Form const &rhs);

protected:
	virtual void		action() const = 0;

public:
	Form();
	Form(std::string name, int gradeSign, int gradeExec)
		throw(GradeTooLowException, GradeTooHighException);
	Form(Form const & src);
	virtual ~Form();

	std::string const	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;

	void				beSigned(Bureaucrat const &b)
		throw(GradeTooLowException);

	void				execute(Bureaucrat const &b) const throw (GradeTooLowException);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &rhs);
		virtual ~GradeTooHighException() throw ();

		GradeTooHighException	&operator=(GradeTooHighException const &rhs);

		virtual const char* what() const throw ();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &rhs);
		virtual ~GradeTooLowException() throw ();

		GradeTooLowException	&operator=(GradeTooLowException const &rhs);

		virtual const char* what() const throw ();
	};
};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif

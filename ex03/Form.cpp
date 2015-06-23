/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 16:52:53 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 00:00:55 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), sign(false), gradeSign(150), gradeExec(150)
{
}

Form::Form(std::string name, int gradeSign, int gradeExec)
	throw(GradeTooLowException, GradeTooHighException) :
		name(name), sign(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

Form::Form(Form const &src) : name(src.name), sign(src.sign),
	gradeSign(src.gradeSign), gradeExec(src.gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	else if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

std::string const	Form::getName() const
{
	return (name);
}

bool				Form::getSigned() const
{
	return (sign);
}

int					Form::getGradeSign() const
{
	return (gradeSign);
}

int					Form::getGradeExec() const
{
	return (gradeExec);
}

void				Form::beSigned(Bureaucrat const &b)
	throw(GradeTooLowException)
{
	if (b.getGrade() <= gradeSign)
		sign = true;
	else
		throw GradeTooLowException();
}

void				Form::execute(Bureaucrat const &b) const
	throw(GradeTooLowException)
{
	if (b.getGrade() <= gradeExec && sign)
		action();
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	return (o	<< "Form " << rhs.getName() << " is "
				<< (rhs.getSigned() ? "signed" : "unsigned")
				<< " and requires grade " << rhs.getGradeSign() << " to be "
				<< "signed and " << rhs.getGradeExec() << " to be executed");
}

Form::GradeTooHighException::GradeTooHighException()
{
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooHighException	&Form::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return (*this);
}

const char							*Form::GradeTooHighException::what() const throw ()
{
	return ("GradeTooHigh");
}

Form::GradeTooLowException::GradeTooLowException()
{
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooLowException	&Form::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return (*this);
}

const char							*Form::GradeTooLowException::what() const throw ()
{
	return ("GradeTooLow");
}

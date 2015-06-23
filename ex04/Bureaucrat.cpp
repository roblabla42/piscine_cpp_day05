/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 13:09:32 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/23 16:21:10 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade(150), name("Bureaucrat")
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
	throw (GradeTooHighException, GradeTooLowException)
	: grade(src.grade), name(src.name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	throw (GradeTooHighException, GradeTooLowException) :
	grade(grade), name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

std::string const	Bureaucrat::getName() const
{
	return (name);
}

int					Bureaucrat::getGrade() const
{
	return (grade);
}

void				Bureaucrat::incGrade()
	throw (GradeTooHighException)
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void				Bureaucrat::decGrade()
	throw (GradeTooLowException)
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void				Bureaucrat::signForm(Form &form)
{
	try {
		std::cout	<< name << " signs " << form.getName() << std::endl;
		form.beSigned(*this);
	} catch (std::exception &e)
	{
		std::cout	<< name << " cannot sign " << form.getName()
					<< " because " << e.what() << std::endl;
		throw e;
	}
}

void				Bureaucrat::executeForm(Form &form)
{
	try {
		std::cout	<< name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	} catch (std::exception &e)
	{
		std::cout	<< name << " cannot execute " << form.getName()
					<< " because " << e.what() << std::endl;
		throw e;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	return (o	<< rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
				<< ".");
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	(void)rhs;
	return (*this);
}

const char							*Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("GradeTooHigh");
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	(void)rhs;
	return (*this);
}

const char							*Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("GradeTooLow");
}

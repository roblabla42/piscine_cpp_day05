/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/22 12:56:15 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/22 20:20:59 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
	int grade;
	std::string const name;
	Bureaucrat			&operator=(Bureaucrat const &rhs);

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade)
		throw (GradeTooHighException, GradeTooLowException);
	Bureaucrat(Bureaucrat const & src)
		throw (GradeTooHighException, GradeTooLowException);
	virtual ~Bureaucrat();

	std::string const	getName() const;
	int					getGrade() const;

	void				incGrade()
		throw (GradeTooHighException);
	void				decGrade()
		throw (GradeTooLowException);

	void				signForm(Form &form);

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

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif

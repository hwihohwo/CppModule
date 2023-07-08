#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;

	public:
		class GradeTooHighException
		{
			public:
				const char * what() const;
		};

		class GradeTooLowException
		{
			public:
				const char * what() const;
		};

		class FormNotSignedException
		{
			public:
				const char * what() const;
		};

		AForm();
		AForm(const std::string name, int grade_to_sign, int grade_to_exec);
		AForm(const AForm& obj);
		AForm& operator =(const AForm& obj);
		virtual ~AForm();

		const std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		bool getIsSigned() const;

		void beSigned(Bureaucrat& obj);
		void execute(Bureaucrat const & executor) const;
		virtual void execute_each_form(Bureaucrat const & executor) const = 0;
};

std::ostream& operator <<(std::ostream& outputStream, const AForm& obj);

#endif
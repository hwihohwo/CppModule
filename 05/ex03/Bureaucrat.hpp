#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

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

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator =(const Bureaucrat& obj);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const & form);
};

std::ostream& operator <<(std::ostream& outstream, const Bureaucrat& obj);

#endif
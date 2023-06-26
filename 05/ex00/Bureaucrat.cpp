#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("default")
{
	this->grade = 75;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
	: name(obj.getName())
{
	this->grade = obj.getGrade();
}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& obj)
{
	if (this == &obj)
		return *this;
	this->grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

std::ostream& operator <<(std::ostream& outstream, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return outstream;
}

const char *Bureaucrat::GradeTooHighException::what() const
{
	return "Grade too high exception";
}

const char *Bureaucrat::GradeTooLowException::what() const
{
	return "Grade too low exception";
}
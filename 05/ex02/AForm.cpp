#include "Form.hpp"

Form::Form()
	: name("default"), grade_to_sign(1), grade_to_exec(1)
{
	this->is_signed = false;
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_exec)
	: name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150)
		throw Form::GradeTooLowException();

	if (grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_exec > 150)
		throw Form::GradeTooLowException();
	this->is_signed = false;
}

Form::Form(const Form& obj)
	: name(obj.getName()), grade_to_sign(obj.getGradeToSign()), grade_to_exec(obj.getGradeToExec())
{
	this->is_signed = obj.getIsSigned();
}

Form& Form::operator =(const Form& obj)
{
	if (this == &obj)
		return *this;
	this->is_signed = obj.getIsSigned();
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const
{
	return this->name;
}

int Form::getGradeToSign() const
{
	return this->grade_to_sign;
}

int Form::getGradeToExec() const
{
	return this->grade_to_exec;
}

bool Form::getIsSigned() const
{
	return this->is_signed;
}

void Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > this->grade_to_sign)
		throw Form::GradeTooLowException();
	else
	{
		obj.signForm(this);
		this->is_signed = true;
	}
}

std::ostream& operator <<(std::ostream& outputStream, const Form& obj)
{
	std::cout << "name : " << obj.getName() << std::endl;
	std::cout << "is signed : " << obj.getIsSigned() << std::endl;
	std::cout << "grade_to_sign : " << obj.getGradeToSign() << std::endl;
	std::cout << "grade_to_exec : " << obj.getGradeToExec();
	return outputStream;
}

const char * Form::GradeTooHighException::what() const
{
	return "Form : Grade too high exception";
}

const char * Form::GradeTooLowException::what() const
{
	return "Form : Grade too low exception";
}

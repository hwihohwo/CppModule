#include "AForm.hpp"

AForm::AForm()
	: name("default"), grade_to_sign(1), grade_to_exec(1)
{
	this->is_signed = false;
}

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_exec)
	: name(name), grade_to_sign(grade_to_sign), grade_to_exec(grade_to_exec)
{
	if (grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > 150)
		throw AForm::GradeTooLowException();

	if (grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	else if (grade_to_exec > 150)
		throw AForm::GradeTooLowException();
	this->is_signed = false;
}

AForm::AForm(const AForm& obj)
	: name(obj.getName()), grade_to_sign(obj.getGradeToSign()), grade_to_exec(obj.getGradeToExec())
{
	this->is_signed = obj.getIsSigned();
}

AForm& AForm::operator =(const AForm& obj)
{
	if (this == &obj)
		return *this;
	this->is_signed = obj.getIsSigned();
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const
{
	return this->name;
}

int AForm::getGradeToSign() const
{
	return this->grade_to_sign;
}

int AForm::getGradeToExec() const
{
	return this->grade_to_exec;
}

bool AForm::getIsSigned() const
{
	return this->is_signed;
}

void AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > this->grade_to_sign)
		throw AForm::GradeTooLowException();
	else
	{
		this->is_signed = true;
		std::cout << obj.getName() << " signed " << this->getName() << std::endl;
	}
}

std::ostream& operator <<(std::ostream& outputStream, const AForm& obj)
{
	std::cout << "name : " << obj.getName() << std::endl;
	std::cout << "is signed : " << obj.getIsSigned() << std::endl;
	std::cout << "grade_to_sign : " << obj.getGradeToSign() << std::endl;
	std::cout << "grade_to_exec : " << obj.getGradeToExec();
	return outputStream;
}

const char * AForm::GradeTooHighException::what() const
{
	return "AForm : Grade too high exception";
}

const char * AForm::GradeTooLowException::what() const
{
	return "AForm : Grade too low exception";
}

const char * AForm::FormNotSignedException::what() const
{
	return "AForm : Form isn't signed yet";
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else if (this->getGradeToExec() < executor.getGrade())
		throw AForm::GradeTooLowException();
	execute_each_form(executor);
}
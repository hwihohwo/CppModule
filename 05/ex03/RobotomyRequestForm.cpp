#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("default", 72, 45), type("robotomy request") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
	: AForm(name, 72, 45), type("robotomy request") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj.getName(), 72, 45), type("robotomy request") {}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute_each_form(Bureaucrat const & executor) const
{
	std::cout << "Drrrrrrrrrrrrrrrr......" << std::endl;
	srand(time(NULL));
	int robotomy_result = rand() % 2;
	if (robotomy_result)
		std::cout << this->getName() << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	std::cout << executor.getName() << " executed " << this->type << std::endl;
}

std::string RobotomyRequestForm::getType() const
{
	return this->type;
}
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("robotomy request", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("robotomy request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm("robotomy request", 72, 45), target(obj.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return *this;
	this->target = obj.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute_each_form(Bureaucrat const & executor) const
{
	std::cout << "Drrrrrrrrrrrrrrrr......" << std::endl;
	srand(time(NULL));
	int robotomy_result = rand() % 2;
	if (robotomy_result)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("presidential pardon", 15, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("presidential pardon", 15, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: AForm(obj.getName(), 15, 5), target(obj.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return *this;
	this->target = obj.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute_each_form(Bureaucrat const & executor) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}
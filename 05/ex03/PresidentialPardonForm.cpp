#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default", 15, 5), type("presidential pardon") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
	: AForm(name, 15, 5), type("presidential pardon") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: AForm(obj.getName(), 15, 5), type("presidential pardon") {}

PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute_each_form(Bureaucrat const & executor) const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->type << std::endl;
}

std::string PresidentialPardonForm::getType() const
{
	return this->type;
}
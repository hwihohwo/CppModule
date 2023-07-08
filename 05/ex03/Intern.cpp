#include "Intern.hpp"

Intern::Intern() {}

Intern& Intern::operator =(const Intern& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string form_names[3] = {"shrubberry creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*newform[3])(const std::string&) = \
	{&Intern::_makeShrubberryCreation, &Intern::_makeRobotomyRequest, &Intern::_makePresidentialPardon};

	for (int i = 0; i < 3; i++)
	{
		if (form_names[i].compare(name) == 0)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*newform[i])(target);
		}
	}
	std::cerr << name << " form does not exist" << std::endl;
	return NULL;
}

AForm* Intern::_makeShrubberryCreation(const std::string& target)
{
	return new ShrubberryCreationForm(target);
}

AForm* Intern::_makeRobotomyRequest(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::_makePresidentialPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}
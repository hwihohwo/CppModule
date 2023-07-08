#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm* _makeShrubberryCreation(const std::string& target);
		AForm* _makeRobotomyRequest(const std::string& target);
		AForm* _makePresidentialPardon(const std::string& target);
		
	public:
		Intern();
		Intern(const Intern& obj);
		Intern& operator =(const Intern& obj);
		~Intern();

		AForm* makeForm(const std::string& name, const std::string& target);
};

#endif
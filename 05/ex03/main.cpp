#include "Bureaucrat.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat* master = new Bureaucrat("master", 1);
	Bureaucrat* newbie = new Bureaucrat("newbie", 150);

	AForm* shrubberry = new ShrubberryCreationForm("home");
	AForm* robotomized = new RobotomyRequestForm("james");
	AForm* presidential = new PresidentialPardonForm("vacation");

	master->executeForm(*shrubberry);
	master->executeForm(*robotomized);
	master->executeForm(*presidential);

	newbie->executeForm(*shrubberry);
	newbie->executeForm(*robotomized);
	newbie->executeForm(*presidential);

	newbie->signForm(*shrubberry);
	newbie->signForm(*robotomized);
	newbie->signForm(*presidential);

	master->signForm(*shrubberry);
	master->signForm(*robotomized);
	master->signForm(*presidential);

	master->executeForm(*shrubberry);
	master->executeForm(*robotomized);
	master->executeForm(*presidential);

	newbie->executeForm(*shrubberry);
	newbie->executeForm(*robotomized);
	newbie->executeForm(*presidential);

	delete master;
	delete newbie;
	delete shrubberry;
	delete robotomized;
	delete presidential;
}
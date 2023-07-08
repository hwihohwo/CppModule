#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat master("master", 1);
	AForm* rrf = NULL;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		master.signForm(*rrf);
		master.executeForm(*rrf);
		delete rrf;
	}

	rrf = someRandomIntern.makeForm("shrubberry creation", "Bender");
	if (rrf)
	{
		master.signForm(*rrf);
		master.executeForm(*rrf);
		delete rrf;
	}
	
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (rrf)
	{
		master.signForm(*rrf);
		master.executeForm(*rrf);
		delete rrf;
	}
	
	rrf = someRandomIntern.makeForm("no exist", "Bender");
	if (rrf)
	{
		master.signForm(*rrf);
		master.executeForm(*rrf);
		delete rrf;
	}
	
}
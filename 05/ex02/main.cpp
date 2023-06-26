#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("a", 25);
	Bureaucrat b("b", 35);
	Form docu("docu", 30, 10);

	try
	{
		Form docu_fail("docu_fail", 0, 23);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form docu_fail("docu_fail", 151, 23);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << docu << std::endl;

	try
	{
		docu.beSigned(b);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		docu.beSigned(a);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << docu << std::endl;

	try
	{
		docu.beSigned(a);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
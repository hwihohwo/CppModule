#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string type;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator =(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();

		void execute_each_form(Bureaucrat const & executor) const;
		std::string getType() const;
};

#endif
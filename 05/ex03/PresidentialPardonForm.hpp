#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string type;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator =(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();

		void execute_each_form(Bureaucrat const & executor) const;
		std::string getType() const;
};

#endif
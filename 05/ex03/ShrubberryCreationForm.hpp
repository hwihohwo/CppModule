#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberryCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberryCreationForm();
		ShrubberryCreationForm(const std::string& target);
		ShrubberryCreationForm(const ShrubberryCreationForm& obj);
		ShrubberryCreationForm& operator =(const ShrubberryCreationForm& obj);
		~ShrubberryCreationForm();

		void execute_each_form(Bureaucrat const & executor) const;
		std::string getTarget() const;
};

#endif
#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberryCreationForm : public AForm
{
	private:
		const std::string type;
	public:
		ShrubberryCreationForm();
		ShrubberryCreationForm(const std::string& name);
		ShrubberryCreationForm(const ShrubberryCreationForm& obj);
		ShrubberryCreationForm& operator =(const ShrubberryCreationForm& obj);
		~ShrubberryCreationForm();

		void execute_each_form(Bureaucrat const & executor) const;
		std::string getType() const;
};

#endif
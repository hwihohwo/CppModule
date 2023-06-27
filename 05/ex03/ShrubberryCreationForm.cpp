#include "ShrubberryCreationForm.hpp"

ShrubberryCreationForm::ShrubberryCreationForm()
	: AForm("default", 145, 137), type("shrubberry creation") {}

ShrubberryCreationForm::ShrubberryCreationForm(const std::string& name)
	: AForm(name, 145, 137), type("shrubberry creation") {}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm& obj)
	: AForm(obj.getName(), 145, 137), type("shrubberry creation") {}

ShrubberryCreationForm& ShrubberryCreationForm::operator =(const ShrubberryCreationForm& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {}

std::string getAsciiTree()
{
	return "         	       _-_\n		    /~~   ~~\\\n		 /~~         ~~\\\n		{               }\n		 \\  _-     -_  /\n		   ~  \\ //  ~\n		_- -   | | _- _\n		  _ -  | |   -_\n		       / \\";
}

void ShrubberryCreationForm::execute_each_form(Bureaucrat const & executor) const
{
	std::string filename = this->getName();
	std::ofstream filewrite;
	std::string ascii_tree = getAsciiTree();

	filewrite.open(filename.append("_shrubbery").c_str());
	if (filewrite.is_open())
	{
		filewrite.write(ascii_tree.c_str(), ascii_tree.length());
		filewrite.close();
	}
	std::cout << executor.getName() << " executed " << this->type << std::endl;
}

std::string ShrubberryCreationForm::getType() const
{
	return this->type;
}
#include "ShrubberryCreationForm.hpp"

ShrubberryCreationForm::ShrubberryCreationForm()
	: AForm("shrubberry creation", 145, 137), target("default") {}

ShrubberryCreationForm::ShrubberryCreationForm(const std::string& target)
	: AForm("shrubberry creation", 145, 137), target(target) {}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm& obj)
	: AForm("shrubberry creation", 145, 137), target(obj.getTarget()) {}

ShrubberryCreationForm& ShrubberryCreationForm::operator =(const ShrubberryCreationForm& obj)
{
	if (this == &obj)
		return *this;
	this->target = obj.getTarget();
	return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {}

std::string getAsciiTree()
{
	return "         	       _-_\n		    /~~   ~~\\\n		 /~~         ~~\\\n		{               }\n		 \\  _-     -_  /\n		   ~  \\ //  ~\n		_- -   | | _- _\n		  _ -  | |   -_\n		       / \\";
}

void ShrubberryCreationForm::execute_each_form(Bureaucrat const & executor) const
{
	std::string filename = this->getTarget();
	std::ofstream filewrite;
	std::string ascii_tree = getAsciiTree();

	filewrite.open(filename.append("_shrubbery").c_str());
	if (filewrite.is_open())
	{
		filewrite.write(ascii_tree.c_str(), ascii_tree.length());
		filewrite.close();
	}
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::string ShrubberryCreationForm::getTarget() const
{
	return this->target;
}
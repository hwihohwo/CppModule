#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "default";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& obj)
{
	this->type = obj.getType();
}

AMateria& AMateria::operator =(const AMateria& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " << this->type << " Materia to " << target.getName() << " *" << std::endl;
}
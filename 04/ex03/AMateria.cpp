#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "default";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "AMateria " << this->type << " constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator =(const AMateria& obj)
{
	std::cout << "AMateria assign operator called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void use(ICharacter& target)
{
	std::cout << "Materia interface." << target.name << std::endl;
}
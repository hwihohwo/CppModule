#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure") {}

Cure::Cure(const Cure& obj)
	: AMateria(obj.getType()) {}

Cure& Cure::operator =(const Cure& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	AMateria* cure = new Cure();

	return cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
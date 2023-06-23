#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->srcMemory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->srcMemory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	this->srcMemory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->srcMemory[i] = NULL;

	for (int i = 0; i < 4; i++)
		if (obj.getSrcMemory()[i])
			this->srcMemory[i] = obj.getSrcMemory()[i]->clone();
}

MateriaSource& MateriaSource::operator =(const MateriaSource& obj)
{
	if (this == &obj)
		return *this;
	for (int i = 0; i < 4; i++)
		if (this->srcMemory[i])
			delete this->srcMemory[i];
	for (int i = 0; i < 4; i++)
		if (obj.getSrcMemory()[i])
			this->srcMemory[i] = obj.getSrcMemory()[i]->clone();
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->srcMemory[i])
			delete this->srcMemory[i];
	delete[] this->srcMemory;
}

AMateria** MateriaSource::getSrcMemory() const
{
	return this->srcMemory;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (!(this->srcMemory[i]))
		{
			this->srcMemory[i] = materia;
			return;
		}
	}
	if (i == 4 && materia)
	{
		std::cout << "srcmemory is full. Delete this materia." << std::endl;
		delete materia;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i;

	for (i = 0; i < 4; i++)
		if (this->srcMemory[i] && this->srcMemory[i]->getType().compare(type) == 0)
			return this->srcMemory[i]->clone();
	std::cout << "Unknown type." << std::endl;
	return NULL;
}
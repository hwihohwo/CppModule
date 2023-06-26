#include "Character.hpp"

Character::Character()
{
	this->name = "default";
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& obj)
{
	this->name = obj.getName();
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;

	for (int i = 0; i < 4; i++)
		if (obj.inventory[i])
			this->inventory[i] = obj.inventory[i]->clone();
}

Character& Character::operator =(const Character& obj)
{
	if (this == &obj)
		return *this;
	this->name = obj.getName();

	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];

	for (int i = 0; i < 4; i++)
		if (obj.inventory[i])
			this->inventory[i] = obj.inventory[i]->clone();
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	delete[] this->inventory;
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
	}
	if (i == 4)
		std::cout << this->name << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}
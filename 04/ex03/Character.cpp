#include "Character.hpp"

Character::Character()
{
	this->name = "default";
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->subinventory = new AMateria*[10];
	for (int i = 0; i < 10; i++)
		this->subinventory[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->subinventory = new AMateria*[10];
	for (int i = 0; i < 10; i++)
		this->subinventory[i] = NULL;
}

Character::Character(const Character& obj)
{
	this->name = obj.getName();
	this->inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->subinventory = new AMateria*[10];
	for (int i = 0; i < 10; i++)
		this->subinventory[i] = NULL;

	for (int i = 0; i < 4; i++)
		if (obj.getInventory()[i])
			this->inventory[i] = obj.getInventory()[i]->clone();
	for (int i = 0; i < 10; i++)
		if (obj.getSubInventory()[i])
			this->inventory[i] = obj.getSubInventory()[i]->clone();
}

Character& Character::operator =(const Character& obj)
{
	if (this == &obj)
		return *this;
	this->name = obj.getName();

	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	for (int i = 0; i < 10; i++)
		if (this->subinventory[i])
			delete this->subinventory[i];

	for (int i = 0; i < 4; i++)
		if (obj.getInventory()[i])
			this->inventory[i] = obj.getInventory()[i]->clone();
	for (int i = 0; i < 10; i++)
		if (obj.getSubInventory()[i])
			this->inventory[i] = obj.getSubInventory()[i]->clone();
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	for (int i = 0; i < 10; i++)
		if (this->subinventory[i])
			delete this->subinventory[i];
	delete[] this->inventory;
	delete[] this->subinventory;
}

std::string const & Character::getName() const
{
	return this->name;
}

AMateria** Character::getInventory() const
{
	return this->inventory;
}

AMateria** Character::getSubInventory() const
{
	return this->subinventory;
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
	int i;

	i = 0;
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return;
	while (this->subinventory[i])
		i++;
	if (i == 10)
	{
		std::cout << this->name << "'s subinventory is full. delete item." << std::endl;
		delete this->inventory[idx];
		this->inventory[idx] = NULL;
	}
	else
	{
		this->subinventory[i] = this->inventory[idx];
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}
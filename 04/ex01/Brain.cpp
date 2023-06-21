#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator =(const Brain& obj)
{
	if (this == &obj)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Brain assign operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const & type)
	: AMateria(type)
{
	std::cout << "Ice " << this->type << " constructor called" << std::endl;
}

Ice::Ice(const Ice& obj)
	: Ice(obj.getType())
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator =(const Ice& obj)
{
	
}
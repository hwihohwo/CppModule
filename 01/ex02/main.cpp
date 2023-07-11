#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brain_PTR = &brain;
	std::string& brain_REF = brain;

	std::cout << "brain address : " << &brain << std::endl;
	std::cout << "brain_PTR address : " << brain_PTR << std::endl;
	std::cout << "brain_REF address : " << &brain_REF << std::endl;
	std::cout << std::endl;

	std::cout << "brain value : " << brain << std::endl;
	std::cout << "brain_PTR value : " << *brain_PTR << std::endl;
	std::cout << "brain_REF value : " << brain_REF << std::endl;
}
#include "Harl.hpp"

void Harl::complain(std::string level)
{
	int	i;
	std::string harl_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*harl_func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (i = 0; i < 4; i++)
	{
		if (harl_level[i] == level)
			break;
	}

	switch (i)
	{
		case 0:
			(this->*harl_func[0])();
		case 1:
			(this->*harl_func[1])();
		case 2:
			(this->*harl_func[2])();
		case 3:
			(this->*harl_func[3])();
			break;
		default:
			std::cout << "Probably complaining about insignificant problems" << std::endl;
	}
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" \
	<< std::endl;
}

void Harl::warning ( void )
{
	std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." \
	<< std::endl;

}

void Harl::error( void )
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}
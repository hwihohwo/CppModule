#ifndef ZOMBIE_HPP
# define ZIMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		void announce(void);

		Zombie(std::string name);

		~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
#ifndef ZOMBIE_HPP
# define ZIMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		void announce(void);

		Zombie(std::string name) : name(name) {
			std::cout << this->name + " turns into zombie!" << std::endl;
		};

		~Zombie() {
			std::cout << this->name + " destroyed!" << std::endl;
		}
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
#ifndef ZOMBIE_HPP
# define ZIMBIE_HPP

#include <iostream>

# define Znum 5

class Zombie {
	private:
		std::string name;

	public:
		void announce(void);

		void setZombieName(std::string name);

		Zombie() {};

		~Zombie() {
			std::cout << this->name + " destroyed!" << std::endl;
		}
};

Zombie* zombieHorde(int N, std::string name);

#endif
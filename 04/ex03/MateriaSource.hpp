#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria** srcMemory;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator =(const MateriaSource& obj);
		~MateriaSource();

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
		AMateria** getSrcMemory() const;
};

#endif
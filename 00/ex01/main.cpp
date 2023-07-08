
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string order;

	while (!phonebook.get_is_exit())
	{
		std::cout << "Please input your order.(ADD, SEARCH, EXIT)" << std::endl << ">";
		std::cin >> order;

		if (order.compare("ADD") == 0)
			phonebook.add_contact();
		else if (order.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (order.compare("EXIT") == 0)
			phonebook.exit_phonebook();
		else
			std::cout << "Wrong order. Please try ADD or SEARCH or EXIT only." << std::endl;
		std::cin.ignore(1000, '\n');
	}
}

#ifndef PHONEBOOK_HPP
#define pHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int	total_contact_num;
		int	is_exit;

		void print_10_char(std::string str);
		int is_valid_index(int index);

	public:
		void add_contact(void);
		void search_contact(void);
		void exit_phonebook(void);
		int get_is_exit(void);

		PhoneBook() {
			this->total_contact_num = 0;
			this->is_exit = 0;
			std::cout << "PhoneBook start!" << std::endl;
		};

		~PhoneBook() {
			std::cout << "Good Bye!" << std::endl;
		};
};

#endif
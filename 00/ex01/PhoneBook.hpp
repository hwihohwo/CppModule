#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int	total_contact_num;
		int	is_exit;

		void print_10_char(std::string str);
		int is_valid_index(int index);
		void cin_fail();

	public:
		void add_contact(void);
		void search_contact(void);
		void exit_phonebook(void);
		int get_is_exit(void);

		PhoneBook();
		~PhoneBook();
};

#endif
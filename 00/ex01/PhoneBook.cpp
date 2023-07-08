#include "PhoneBook.hpp"

void PhoneBook::print_10_char(std::string str)
{
	int length = str.length();

	if (length > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << str.at(i);
		std::cout << ".";
	}
	else
	{
		for (int i = 0; i < 10 - length; i++)
			std::cout << ' ';
		std::cout << str;
	}
}

int PhoneBook::is_valid_index(int index)
{
	if (index < 0 || index > 7)
		return (0);
	else if (index >= this->total_contact_num)
		return (0);
	else
		return (1);
}

void PhoneBook::cin_fail(void)
{
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "Wrong index. Please try again." << std::endl;
}

int PhoneBook::get_is_exit(void)
{
	return this->is_exit;
}

void PhoneBook::add_contact(void)
{
	std::string info;

	std::cout << "First name : ";
	std::cin >> info;
	this->contacts[this->total_contact_num % 8].set_first_name(info);
	std::cout << "Last name : ";
	std::cin >> info;
	this->contacts[this->total_contact_num % 8].set_last_name(info);
	std::cout << "Nickname : ";
	std::cin >> info;
	this->contacts[this->total_contact_num % 8].set_nickname(info);
	std::cout << "Phone number(ex. 000-0000-0000) : ";
	std::cin >> info;
	this->contacts[this->total_contact_num % 8].set_phone_number(info);
	std::cout << "Darkest secret : ";
	std::cin >> info;
	this->contacts[this->total_contact_num % 8].set_darkest_secret(info);
	this->total_contact_num++;
}

void PhoneBook::search_contact(void)
{
	int index_to_find;

	if (this->total_contact_num == 0)
	{
		std::cout << "Please add any contact first." << std::endl;
		return;
	}
	std::cout << "     index|" << "first name|" << " last name|" << "  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (i >= this->total_contact_num)
			break;
		std::cout << "         " << i << '|';
		this->print_10_char(this->contacts[i].get_first_name());
		std::cout << '|';
		this->print_10_char(this->contacts[i].get_last_name());
		std::cout << '|';
		this->print_10_char(this->contacts[i].get_nickname());
		std::cout << '|' << std::endl;
	}
	while (1)
	{
		std::cout << "Please input index you want to see more information" << std::endl << '>';
		std::cin >> index_to_find;
		if (!is_valid_index(index_to_find) || std::cin.fail())
		{
			cin_fail();
			continue;
		}
		else
			break;
	}
	std::cout << "First name : " << this->contacts[index_to_find].get_first_name() << std::endl;
	std::cout << "Last name : " << this->contacts[index_to_find].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->contacts[index_to_find].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->contacts[index_to_find].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << this->contacts[index_to_find].get_darkest_stcret() << std::endl;
	std::cin.ignore(1000, '\n');
}

void PhoneBook::exit_phonebook(void)
{
	this->is_exit = 1;
}

PhoneBook::PhoneBook() {
	this->total_contact_num = 0;
	this->is_exit = 0;
	std::cout << "PhoneBook start!" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "Good Bye!" << std::endl;
}
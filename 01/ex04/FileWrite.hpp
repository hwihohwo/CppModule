#ifndef FILEWRITE_HPP
# define FILEWRITE_HPP

#include <fstream>
#include <iostream>

class FileWrite
{
	private:
		std::string str_to_find;
		std::string str_to_write;
		std::string replaced_str;
		std::ofstream filewrite;

	public:
		void replace_str(std::string& src_string);
		void write_replaced_str();

		FileWrite(std::string filename, std::string str1, std::string str2);
};

#endif
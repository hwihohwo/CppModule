#ifndef FILEREAD_HPP
# define FILEREAD_HPP

#include <fstream>
#include <iostream>

class FileReplace
{
	private:
		std::string filename;
		std::string file_content;
		std::ifstream fileread;

		std::string str_to_find;
		std::string str_to_write;
		std::string replaced_str;
		std::ofstream filewrite;

	public:
		void replace_str(std::string& src_string);

		FileReplace(std::string filename, std::string str1, std::string str2);
};

#endif
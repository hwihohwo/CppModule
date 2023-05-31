#ifndef FILEREAD_HPP
# define FILEREAD_HPP

#include <fstream>
#include <iostream>

class FileRead
{
	private:
		std::string filename;
		std::string file_content;
		std::ifstream fileread;

	public:
		std::string& get_file_content();

		FileRead(std::string filename);
};

#endif
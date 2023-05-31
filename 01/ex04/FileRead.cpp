#include "FileRead.hpp"

FileRead::FileRead(std::string filename)
{
	std::string tmp;

	this->filename = filename;
	this->fileread.open(this->filename.c_str());
	if (this->fileread.is_open())
	{
		while (!this->fileread.eof())
		{
			std::getline(this->fileread, tmp);
			this->file_content.append(tmp);
		}
		this->fileread.close();
	}
}

std::string& FileRead::get_file_content(void)
{
	return this->file_content;
}
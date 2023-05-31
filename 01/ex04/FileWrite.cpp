#include "FileWrite.hpp"

FileWrite::FileWrite(std::string filename, std::string str1, std::string str2)
	:str_to_find(str1), str_to_write(str2)
{
	std::string tmp = ".replace";
	std::string new_filename = filename.append(tmp);
	this->filewrite.open(new_filename.c_str());
}

void FileWrite::replace_str(std::string& src_string)
{
	int	index;

	if (this->filewrite.is_open())
	{
		while ((index = src_string.find(this->str_to_find)) >= 0)
		{
			src_string.erase(index, this->str_to_find.length());
			src_string.insert(index, this->str_to_write);
		}
		this->replaced_str = src_string;
	}
}

void FileWrite::write_replaced_str(void)
{
	if (this->filewrite.is_open())
	{
		this->filewrite.write(this->replaced_str.c_str(), this->replaced_str.length());
		this->filewrite.close();
	}
}
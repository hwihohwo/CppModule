#include "FileReplace.hpp"

FileReplace::FileReplace(std::string filename, std::string str1, std::string str2)
	:str_to_find(str1), str_to_write(str2)
{

	this->filename = filename;
	this->fileread.open(this->filename.c_str());
	if (this->fileread.is_open())
	{
		std::string tmp;
		while (!this->fileread.eof())
		{
			std::getline(this->fileread, tmp);
			this->file_content.append(tmp);
			if (!this->fileread.eof())
				this->file_content.append("\n");
		}
		this->fileread.close();
	

		std::string new_filename = filename.append(".replace");
		this->filewrite.open(new_filename.c_str());

		this->replace_str(this->file_content);
	}
	else
		std::cerr << "Can't open file" << std::endl;
}

void FileReplace::replace_str(std::string& src_string)
{
	int	index;

	if (this->filewrite.is_open())
	{
		while ((index = src_string.find(this->str_to_find)) >= 0 && 
				this->str_to_find.length() > 0)
		{
			src_string.erase(index, this->str_to_find.length());
			src_string.insert(index, this->str_to_write);
		}
		this->replaced_str = src_string;
		this->filewrite.write(this->replaced_str.c_str(), this->replaced_str.length());
		this->filewrite.close();
	}
}
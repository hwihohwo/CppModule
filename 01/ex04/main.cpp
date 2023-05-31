#include "FileRead.hpp"
#include "FileWrite.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	
	FileRead file_read(argv[1]);
	FileWrite file_write(argv[1], argv[2], argv[3]);

	file_write.replace_str(file_read.get_file_content());
	file_write.write_replaced_str();
	return (0);
}

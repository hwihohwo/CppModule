#include "FileReplace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	
	FileReplace file_replace(argv[1], argv[2], argv[3]);
	return (0);
}

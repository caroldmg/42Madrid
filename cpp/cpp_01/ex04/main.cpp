#include "Replace.hpp"

int	main (int argc, char **argv)
{
	Replace replace(argv[1]);
	if (argc != 4)
		std::cout << "wrong input: try <filename>, s1, s2" << std::endl;
	replace.replaceString(argv[2], argv[3]);
}
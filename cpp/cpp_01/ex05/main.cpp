
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Error: wrong args. Try with one of the following: <DEBUG> <INFO> <WARNING> <ERROR> " << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}


#include <iostream>

int main(void)
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "ADDRESS OF VARIABLE => " << &stringVAR << std::endl;
	std::cout << "ADDRESS OF POINTER => " << stringPTR << std::endl;
	std::cout << "ADDRESS OF REFERENCE => " << &stringREF << std::endl;
	
	std::cout << "------------------------------" << std::endl;
	std::cout << "VALUE OF VARIABLE => " << stringVAR << std::endl;
	std::cout << "VALUE OF POINTER => " << *stringPTR << std::endl;
	std::cout << "VALUE OF REFERENCE => " << stringREF << std::endl;
}

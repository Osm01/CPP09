
#include "RPN.h"

int main(int argc, const char **argv)
{
	if (argc > 1)
		post_reverse_notation(argc, argv);
	else
		std::cout << RED << "Error on parameter" << RESET << std::endl;
}
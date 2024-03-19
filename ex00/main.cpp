
#include "BitcoinExchange.h"

int main(int argc, const char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange b(argv[1]);
		b.fill_data();
		b.fill_input_data();
	}
	else
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
	return 0;
}
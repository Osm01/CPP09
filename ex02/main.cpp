
#include "PmergeMe.h"

int main(int argc, const char **argv)
{
	std::vector<int> v;
	if (argc > 2)
	{
		int index = 0;
		while (++index < argc)
		{
			char *endptr;
			double value = strtol(argv[index], &endptr, 10);
			if (*endptr || value < 0 || value > INT_MAX)
				return (std::cout << RED << "Error" << RESET << std::endl, 0);
			v.push_back(value);
		}
		mergeSort_vector(v, 0, v.size() - 1);

	}
	else
		std::cout << RED << "Insufficient <`element`>" << RESET << std::endl;
	return 0;
}
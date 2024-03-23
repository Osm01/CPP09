
#include "PmergeMe.h"

void	apply_on_vector(std::vector<int> &v)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	std::vector<int> data_sorted = ford_johnson_vector(v);
	gettimeofday(&end, NULL);
	unsigned int i = -1;
	std::cout << BLUE << "Before : " << RESET;
	while (++i < v.size())
		std::cout << v[i] << " ";
	std::cout << YELLOW << "\nAfter : " << RESET;
	i = -1;
	while (++i < data_sorted.size())
		std::cout << data_sorted[i] << " ";
	std::cout << GREEN <<  "\nTime to process a range of " << v.size() << " elements with std::vector : " \
	<< (end.tv_usec - start.tv_usec) << " us"  << RESET << std::endl;
}

void	apply_on_deque(std::deque<int> &v)
{
	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	std::deque<int> data_sorted = ford_johnson_deque(v);
	gettimeofday(&end, NULL);
	unsigned int i = -1;
	std::cout << BLUE << "Before : " << RESET;
	while (++i < v.size())
		std::cout << v[i] << " ";
	std::cout << YELLOW << "\nAfter : " << RESET;
	i = -1;
	while (++i < data_sorted.size())
		std::cout << data_sorted[i] << " ";
	std::cout << GREEN <<  "\nTime to process a range of " << v.size() << " elements with std::deque : " \
	<< (end.tv_usec - start.tv_usec) << " us"  << RESET << std::endl;
}

int main(int argc, const char **argv)
{
	std::vector<int> v;
	std::deque<int> q;

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
			q.push_back(value);
		}
		apply_on_vector(v);
		apply_on_deque(q);

	}
	else
		std::cout << RED << "Insufficient <`element`>" << RESET << std::endl;
	return 0;
}
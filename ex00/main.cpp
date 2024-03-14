
#include "BitcoinExchange.h"

int main(int argc, const char **argv)
{
	static_cast<void>(argv);
	static_cast<void>(argc);
//	if (argc == 2)
//	{
//
//	}
//	else
//		std::cout << RED << "Error: could not open file." << RESET << std::endl;
	{
		BitcoinExchange btc("test");
		std::cout << btc.checking_value("2147483648") << std::endl;
	}
	{
//		std::map<std::string, double> map;
//		map["20-20-01"] = 1;
//		map["20-20-02"] = 10;
//		map["20-20-04"] = 100;
//		map["20-20-06"] = 1000;
//		std::map<std::string, double>::iterator it;
//		it = map.lower_bound("20-20-05");
//		std::cout << it->first << " | " << it->second << std::endl;

	}
	return 0;
}
//
// Created by ouidriss on 3/12/24.
//

#ifndef CPP09_BITCOINEXCHANGE_H
#define CPP09_BITCOINEXCHANGE_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

# include <iostream>
# include <map>
# include <vector>
# include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string.h>


class BitcoinExchange {
private :
	const char						*input_file_name;
	std::map<std::string, double>	input_data;
	std::map<std::string, double>	data;
	std::vector<int>				days;
public:
	BitcoinExchange(const char *file_name);
	BitcoinExchange(const BitcoinExchange &b);
	BitcoinExchange	&operator=(const BitcoinExchange &b);
	std::ifstream	*read_file(const char *file);
	void			fill_data(void);
	void			fill_input_data(void);
	int 			checking_key(std::string key);
	int 			checking_value(std::string value);
	void			display_data(void);
	~BitcoinExchange();
};


#endif //CPP09_BITCOINEXCHANGE_H

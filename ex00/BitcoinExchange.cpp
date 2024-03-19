//
// Created by ouidriss on 3/12/24.
//

#include "BitcoinExchange.h"


BitcoinExchange::BitcoinExchange(const char *file_name)
{
	this->input_file_name = file_name;
	this->days.push_back(31);
	this->days.push_back(28);
	this->days.push_back(31);
	this->days.push_back(30);
	this->days.push_back(31);
	this->days.push_back(30);
	this->days.push_back(31);
	this->days.push_back(31);
	this->days.push_back(30);
	this->days.push_back(31);
	this->days.push_back(30);
	this->days.push_back(31);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &b)
{
	*this = b;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &b){
	if (this != &b)
		this->days = b.days;
	return (*this);
}

std::ifstream *BitcoinExchange::read_file(const char *file)
{
	std::ifstream *in = new std::ifstream (file);
	if (!(*in))
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		delete in;
		return NULL;
	}
	return in;
}

void BitcoinExchange::fill_data()
{
	std::string	key;
	std::string	value;
	std::string	data;
	int 		first_is_key;
	std::ifstream *in = read_file("data.csv");

	if (!in)
		return (std::cout << RED << "data.csv not exist" << RESET << std::endl , static_cast<void>(exit(0)));
	while (getline(*in, data))
	{
		value.clear();
		key.clear();
		first_is_key = 1;
		std::stringstream ss(data);
		while (getline(ss, value, ','))
		{
			if (first_is_key)
			{
				key = value;
				value.clear();
				first_is_key = 0;
			}
		}
		if (key.empty() || value.empty())
			return (std::cout << RED << "Something wrong on data.csv file" << RESET << std::endl ,delete in ,static_cast<void>(exit(0)));
		this->data[key] = strtod(value.c_str(), NULL);
	}
	return (std::cout << GREEN << "data.csv has been successfully stored" << RESET << std::endl, delete in);
}

int	BitcoinExchange::checking_key(std::string key)
{
	std::stringstream	ss(key);
	std::string			check;
	int 				i = 0;
	int 				month = 0;
	char				*endptr;

	while (getline(ss, check, '-'))
	{
		int v = strtol(check.c_str(), &endptr, 10);
		if (*endptr && *endptr != 32)
			return 0;
		else
		{
			if (i == 0)
			{
				if (v < 2009)
					return 0;
				v % 4 == 0 ? this->days[0] = 29 : this->days[0] = 31;
			}
			else if (i == 1)
			{
				if (v < 1 || v > 12)
					return 0;
				month = v;
			}
			else if (month == 0 || (i == 2 && (v < 1 || v > this->days[month - 1])))
				return 0;
		}
		i ++;
	}
	if (i != 3)
		return 0;
	return 1;
}

int	BitcoinExchange::checking_value(std::string value)
{
	char	*endptr;
	double	v;

	v = strtod(value.c_str(), &endptr);
	if ((strlen(endptr) > 1) || (strlen(endptr) == 1 && endptr[0] != 'f'))
		return (std::cout << "Error: bad input => " << value << std::endl ,0);
	if (v < 0 || v > 1000)
	{
		if (v > 1000)
			return (std::cout << RED << "Error: too large a number." << RESET << std::endl, 0);
		else
			return (std::cout << RED << "Error: not a positive number." << RESET << std::endl, 0);
	}
	return 1;
}

void BitcoinExchange::fill_input_data(void)
{
	std::string	key;
	std::string value;
	std::string line;
	int 		first_is_key;
	int			count;
	std::ifstream *in = read_file(this->input_file_name);

	if (!in)
		return ;
	do {
		getline(*in, line);
	} while (line.empty());
	if (line != "date | value")
		return (std::cout << RED << "Incorrect input file" << RESET << std::endl, delete in, static_cast<void>(exit(0)));
	while (getline(*in, line))
	{
		std::stringstream ss(line);
		key.empty();
		value.empty();
		first_is_key = 1;
		count = 0;
		while (getline(ss,value, '|'))
		{
			if (first_is_key)
			{
				key = value;
				first_is_key = 0;
			}
			count ++;
		}
		if (count != 2)
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			if (!checking_key(key))
				std::cout << "Error: bad input => " << line << std::endl;
			else if (checking_value(value))
			{
				if (key < "2009-01-02")
					std::cout << RED <<  "value tooooo low "  << RESET << std::endl;
				else
				{
					std::map<std::string , double>::iterator it = this->data.lower_bound(key);
					it --;
					std::cout << key << "=>" << value << " = " << it->second * strtod(value.c_str(), NULL) << std::endl;
				}
			}
		}
	}
	delete in;
}

void BitcoinExchange::display_data(void)
{
	for (std::map<std::string, double>::iterator it = this->data.begin() ; it != data.end() ; it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "Calling destructor" <<  RESET << std::endl;
}
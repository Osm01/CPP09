//
// Created by Oussama Idrissi on 3/15/24.
//

#include "RPN.h"

int	calculate(char op, int v1, int v2)
{
	switch (op) {
		case '+':
			return v2 + v1;
		case '-':
			return v2 - v1;
		case '*':
			return v2 * v1;
		case '/':
			return v2 / v1;
		default:
			return (std::cout << RED << "??" << RESET << std::endl , 0);
	}
}

void	display_result(std::stack<int> &s)
{
	if (s.size() != 1)
		return (static_cast<void>(std::cout << RED << "Error" << RESET << std::endl));
	std::cout << GREEN << s.top() << RESET << std::endl;
}

void	post_reverse_notation(int argc, const char **argv)
{
	int	index = 0;
	std::stack<int> s;

	while (++index < argc)
	{
		std::string str(argv[index]);
		for (std::string::iterator it = str.begin() ; it != str.end() ; it ++)
		{
			if (*it >= '0' && *it <= '9')
			{
				s.push(*it - 48);
			}
			else if ((*it != ' ' && *it != '\t'))
			{
				if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
				{
					if (s.size() > 1)
					{
						int v1 = s.top();
						s.pop();
						int v2 = s.top();
						s.pop();
						if (v1 == 0 && *it == '/')
							return (static_cast<void>(std::cout << RED << "Error" << std::endl));
						s.push(calculate(*it, v1, v2));
					}
					else
						return (static_cast<void>(std::cout << RED << "Error" << std::endl));
				}
				else
					return (static_cast<void>(std::cout << RED << "Error" << std::endl));
			}
		}
	}
	display_result(s);
}

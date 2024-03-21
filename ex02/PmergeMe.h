//
// Created by Oussama Idrissi on 3/16/24.
//

#ifndef PMERGEME_H
#define PMERGEME_H


# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

# include <iostream>
# include <vector>
# include <stack>
# include <sstream>
# include <stdlib.h>
# include <list>
# include <climits>

std::vector<int>	ford_johnson_vector(std::vector<int> &data);
void				mergeSort_vector(std::vector<int> &data , int left , int right);
void				merge(std::vector<int> &data, int left, int mid, int right);

#endif //CPP09_PMERGEME_H

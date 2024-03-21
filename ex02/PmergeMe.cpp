//
// Created by Oussama Idrissi on 3/16/24.
//

#include "PmergeMe.h"

void				merge(std::vector<int> &data, int left, int mid, int right)
{
//	std::vector<int> left_vector;
//	std::vector<int> right_vector;
//
//	unsigned int i = -1;
//	while (++i <= mid)
//		left_vector.push_back(data[left + i]);
//	i = -1;
//	while (++i < (right - mid))
//		right_vector.push_back(data[(mid + 1) + i]);
//	i = -1;
//	while (++i < left_vector.size())
//		std::cout << left_vector[i] << " " ;
//	std::cout << std::endl;
//	i = -1;
//	while (++i < right_vector.size())
//		std::cout << right_vector[i] << " " ;
//	std::cout << "\n------------" <<std::endl;
//	int l, r;
//	i = 0;
//	l = r = i;
//	while (i < left_vector.size() && i < right_vector.size())
//	{
//		if (left_vector[l] < right_vector[r])
//			data[i] = right_vector[r ++];
//		else
//			data[i] = left_vector[l ++];
//		i ++;
//	}
//	while (i < left_vector.size())
//	{
//		data[i] = left_vector[i];
//		i ++;
//	}
//	while (i < right_vector.size())
//	{
//		data[i] = right_vector[i];
//		i ++;
//	}
}

void	mergeSort_vector(std::vector<int> &data , int left , int right)
{
//	for(std::vector<int>::iterator i = data.begin(); i != data.end(); i ++)
//		std::cout << *i << " ";
//	std::cout << std::endl;

	if (left < right)
	{
		int mid = (right + left) / 2;
		mergeSort_vector(data, left, mid);
		mergeSort_vector(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}

//void	mergeSort_recursion_vector(std::vector<int> &data, int left, int mid, int right)
//{
//}

std::vector<int>	ford_johnson_vector(std::vector<int> &data)
{
	std::vector<int> big_v;
	int size = data.size() % 2 ? data.size() - 1 : data.size();
	int i;

	i = 0;
	while (i < size)
	{
		if (data[i] > data[i + 1]) {
			big_v.push_back(data[i]);
		}
		i += 2;
	}
	return big_v;
}
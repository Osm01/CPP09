//
// Created by Oussama Idrissi on 3/16/24.
//

#include "PmergeMe.h"

void				merge(std::vector<int> &data, int left, int mid, int right)
{
	std::vector<int> left_vector;
	std::vector<int> right_vector;

	int i = -1;
	while (++i <= (mid - left))
		left_vector.push_back(data[left + i]);
	i = -1;
	while (++i < (right - mid))
		right_vector.push_back(data[(mid + 1) + i]);
	unsigned int l, r;
	i = left;
	l = r = 0;
	while (l < left_vector.size() && r < right_vector.size())
	{
		if (left_vector[l] > right_vector[r])
			data[i] = right_vector[r ++];
		else
			data[i] = left_vector[l ++];
		i ++;
	}
	while (l < left_vector.size())
		data[i ++] = left_vector[l ++];
	while (r < right_vector.size())
		data[i ++] = right_vector[r ++];
}


void	mergeSort_vector(std::vector<int> &data , int left , int right)
{

	if (left < right)
	{
		int mid = (right + left) / 2;
		mergeSort_vector(data, left, mid);
		mergeSort_vector(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}

std::vector<int>	ford_johnson_vector(std::vector<int> &data)
{
	std::vector<int> big_v;
	unsigned int size = data.size() % 2 ? data.size() - 1 : data.size();
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (data[i] > data[i + 1]) {
			int tmp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tmp;
		}
		big_v.push_back(data[i + 1]);
		i += 2;
	}
	mergeSort_vector(big_v, 0 , big_v.size() - 1);
	i = 0;
	while (i < data.size())
	{
		std::vector<int>::iterator pos = std::lower_bound(big_v.begin(), big_v.end(), data[i]);
		big_v.insert(pos, data[i]);
		i += 2;
	}
	return big_v;
}

//////////////////////////////////////

void				merge_deque(std::deque<int> &data, int left, int mid, int right)
{
	std::deque<int> left_deque;
	std::deque<int> right_deque;

	int i = -1;
	while (++i <= (mid - left))
		left_deque.push_back(data[left + i]);
	i = -1;
	while (++i < (right - mid))
		right_deque.push_back(data[(mid + 1) + i]);
	unsigned int l, r;
	i = left;
	l = r = 0;
	while (l < left_deque.size() && r < right_deque.size())
	{
		if (left_deque[l] > right_deque[r])
			data[i] = right_deque[r ++];
		else
			data[i] = left_deque[l ++];
		i ++;
	}
	while (l < left_deque.size())
		data[i ++] = left_deque[l ++];
	while (r < right_deque.size())
		data[i ++] = right_deque[r ++];
}


void	mergeSort_deque(std::deque<int> &data , int left , int right)
{

	if (left < right)
	{
		int mid = (right + left) / 2;
		mergeSort_deque(data, left, mid);
		mergeSort_deque(data, mid + 1, right);
		merge_deque(data, left, mid, right);
	}
}

std::deque<int>	ford_johnson_deque(std::deque<int> &data)
{
	std::deque<int> big_v;
	unsigned int size = data.size() % 2 ? data.size() - 1 : data.size();
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (data[i] > data[i + 1]) {
			int tmp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tmp;
		}
		big_v.push_back(data[i + 1]);
		i += 2;
	}
	mergeSort_deque(big_v, 0 , big_v.size() - 1);
	i = 0;
	while (i < data.size())
	{
		std::deque<int>::iterator pos = std::lower_bound(big_v.begin(), big_v.end(), data[i]);
		big_v.insert(pos, data[i]);
		i += 2;
	}
	return big_v;
}

#include "PmergeMe.h"

int main()
{
    std::list<int> l;
    l.push_back(10);
    l.insert(l.begin(), 20);
    std::vector<int> v;
    v.push_back(10);
    v.insert(v.begin(), 20);
    for (std::list<int>::iterator it = l.begin() ; it != l.end() ; it ++)
        std::cout << *it << std::endl;
    for (std::vector<int>::iterator it = v.begin() ; it != v.end() ; it ++)
        std::cout << *it << std::endl;
    
}
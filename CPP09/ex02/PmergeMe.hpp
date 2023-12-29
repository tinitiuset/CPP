#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <ctime>

class PmergeMe {

public:
	PmergeMe(char **);
	~PmergeMe();

private:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	void loadData(char **);

	double mergeInsertSort(std::list<int>::iterator, std::list<int>::iterator);
	double mergeInsertSort(std::vector<int>&, int, int);

	std::list<int> _list;
	std::vector<int> _vector;

};

#endif

#include "PmergeMe.hpp"

void insertionSort(std::list<int>::iterator begin, std::list<int>::iterator end) {
	for (std::list<int>::iterator i = begin; i != end; ++i) {
		int key = *i;
		std::list<int>::iterator j = i;
		while (j != begin && *(std::prev(j)) > key) {
			*j = *(std::prev(j));
			--j;
		}
		*j = key;
	}
}

void insertionSort(std::vector<int>& vec, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = vec[i];
		int j = i - 1;

		while (j >= left && vec[j] > key) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void merge(std::list<int>::iterator begin, std::list<int>::iterator mid, std::list<int>::iterator end) {
	std::list<int> temp;
	std::list<int>::iterator i = begin;
	std::list<int>::iterator j = mid;
	while (i != mid && j != end) {
		temp.push_back((*i <= *j) ? *i++ : *j++);
	}
	while (i != mid) {
		temp.push_back(*i++);
	}
	while (j != end) {
		temp.push_back(*j++);
	}
	std::copy(temp.begin(), temp.end(), begin);
}

void merge(std::vector<int>& vec, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	std::vector<int> temp;

	while (i <= mid || j <= right) {
		if (i > mid) {
			temp.push_back(vec[j++]);
		} else if (j > right) {
			temp.push_back(vec[i++]);
		} else {
			temp.push_back((vec[i] <= vec[j]) ? vec[i++] : vec[j++]);
		}
	}

	for (i = left; i <= right; i++) {
		vec[i] = temp[i - left];
	}
}

double PmergeMe::mergeInsertSort(std::list<int>::iterator begin, std::list<int>::iterator end) {
	const int INSERTION_SORT_THRESHOLD = 32;

	clock_t clock_start = clock();

	if (std::distance(begin, end) <= INSERTION_SORT_THRESHOLD) {
		insertionSort(begin, end);
	} else {
		std::list<int>::iterator mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		mergeInsertSort(begin, mid);
		mergeInsertSort(mid, end);
		merge(begin, mid, end);
	}

	clock_t clock_end = clock();
	double duration = (double)(clock_end - clock_start) / CLOCKS_PER_SEC * 1000000;

	return duration;
}

double PmergeMe::mergeInsertSort(std::vector<int>& vec, int left, int right) {
	const int INSERTION_SORT_THRESHOLD = 32;

	clock_t start = clock();

	if (right - left <= INSERTION_SORT_THRESHOLD) {
		insertionSort(vec, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertSort(vec, left, mid);
		mergeInsertSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}

	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	return duration;
}

void PmergeMe::loadData(char **argv) {
	int i = 1;
	while (argv[i]) {
		if (std::stoi(argv[i]) > 0) {
			_list.push_back(std::stoi(argv[i]));
			_vector.push_back(std::stoi(argv[i]));
		}
		else
			throw std::invalid_argument("Only positive values are tolerated.");
		i++;
	}
}

PmergeMe::PmergeMe(char **argv) {

	loadData(argv);

	std::cout << "Before: ";
	for (std::vector<int>::const_iterator i = _vector.begin(); i != _vector.end(); ++i) {
		std::cout << *i << ' ';
	}
	std::cout << '\n';

	{
		std::vector<int> temp(_vector);
		std::sort(temp.begin(), temp.end());
		std::cout << "After: ";
		for (std::vector<int>::const_iterator i = temp.begin(); i != temp.end(); ++i)
			std::cout << *i << ' ';
		std::cout << '\n';
	}

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << mergeInsertSort(_vector, 0, _vector.size() - 1) << " us" << std::endl;
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << mergeInsertSort(_list.begin(), _list.end()) << " us" << std::endl;

	{
		std::vector<int> temp(_vector);
		std::sort(temp.begin(), temp.end());
		if (temp == _vector)
			std::cout << "std::vector is sorted" << std::endl;
		else
			std::cout << "std::vector is not sorted" << std::endl;
	}

	{
		std::list<int> temp(_list);
		temp.sort();
		if (temp == _list)
			std::cout << "std::list is sorted" << std::endl;
		else
			std::cout << "std::list is not sorted" << std::endl;
	}
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_list = other._list;
		_vector = other._vector;
	}
	return *this;
}
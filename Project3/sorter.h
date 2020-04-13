#pragma once
#define MAXSIZE = 100000
#include <vector>
template <class t>
class sorter
{
private:
	std::vector<t> a;
	size_t comparissonCount;
	size_t swapCount;
public:
	sorter();
	sorter(std::vector<t> &arr);
	void setArray(std::vector<t> &arr);
	std::vector<t> getArray();
	//Sorts
	void bubbleSort();
	void insertionSort();
	void quickSort(size_t first, size_t last);
	//gets
	size_t getCompCount();
	size_t getSwapCount();
	size_t getSize();
	//reset counts
	void resetCounts();
};


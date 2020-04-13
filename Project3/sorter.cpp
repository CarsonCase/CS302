#include "sorter.h"
#include <iostream>

template <class t>
sorter<t>::sorter() {
	resetCounts();
}
template <class t>
sorter<t>::sorter(std::vector<t> &arr) {
	resetCounts();
	a = arr;
}
template <class t>
void sorter<t>::setArray(std::vector<t> &arr) {
	a = arr;
}

template <class t>
std::vector<t> sorter<t>::getArray() {
	return a;
}
template <class t>
void sorter<t>::bubbleSort() {
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			//std::cout << i << " " << j << std::endl;
			if (a[j] < a[i]) {
				//swap
				t temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				swapCount++;
			}
			comparissonCount++;
		}
	}
	
}

template <class t>
void sorter<t>::insertionSort() {
	for (int i = 1; i < a.size(); i++) {
		t toInsert = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] > toInsert) {
				//insert and erase the old one we are moving
				a.erase(a.begin() + i);
				a.insert(a.begin()+j, toInsert);
				swapCount++;
				break;
			}
			comparissonCount++;
		}
	}
}

template <class t>
void sorter<t>::quickSort(size_t first, size_t last) {
	int pivot = last;
	int i = first;
	bool is_swap = false;
	if (i >= pivot) {
		return;
	}
	while (i < pivot) {
		/*std::cout << "[";
		for (int j = 0; j < a.size(); j++) {
			std::cout << a[j] << ", ";
		}
		std::cout << "]" << std::endl;*/

		if (a[i] < a[pivot]) {
			comparissonCount++;
			i++;
		}
		comparissonCount++;
		if (i == pivot) {
			break;
		}
		comparissonCount++;
		if (a[i] >= a[pivot]) {
			//std::cout << a[i] << " " << a[pivot] << std::endl;
			a.insert(a.begin() + pivot + 1, a[i]);
			a.erase(a.begin() + i);
			pivot--;
			swapCount++;
			is_swap = true;
		}
		comparissonCount++;
	}
	if (is_swap) {
		quickSort(first, pivot - 1);
		quickSort(pivot + 1, last);
	}
	

}

template <class t>
size_t sorter<t>::getCompCount() {
	return comparissonCount;
}
template <class t>
size_t sorter<t>::getSwapCount() {
	return swapCount;
}
template <class t>
size_t sorter<t>::getSize() {
	return a.size();
}
template <class t>
void sorter<t>::resetCounts() {
	comparissonCount = 0;
	swapCount = 0;
}
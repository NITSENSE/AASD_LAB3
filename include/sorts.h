#pragma once
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
void SelectionSort(vector<T>& sort) {
	for (size_t i = 0; i < sort.size(); ++i) {
		size_t temp = i;
		for (size_t j = i; j < sort.size(); ++j) {
			if (sort[temp] > sort[j])
				temp = j;
		}
		if (i != temp)
			swap(sort[i], sort[temp]);
	}
}

template<typename T>
void BubbleSort(vector<T>& sort) {
	for (size_t i = sort.size() - 1; i > 0; --i) {
		for (size_t j = 1; j <= i; ++j) {
			if (sort[j] < sort[j - 1])
				swap(sort[j], sort[j - 1]);
		}
	}

}

template<typename T>
void InsertionSort(vector<T>& sort) {
	for (size_t i = 1; i < sort.size(); ++i) {
		for (size_t j = i; j >= 1 && sort[j - 1] > sort[j]; j--)
			swap(sort[j], sort[j - 1]);
	}
}
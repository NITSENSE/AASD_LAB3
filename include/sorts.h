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
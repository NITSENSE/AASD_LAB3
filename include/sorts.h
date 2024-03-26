#pragma once
#include <vector>
#include <iostream>

using namespace std;


template<typename T>
void SelectionSort(vector<T>& sort) {
	for (int i = 0; i < sort.size(); ++i) {
		int temp = i;
		for (int j = i; j < sort.size(); ++j) {
			if (sort[temp] > sort[j])
				temp = j;
		}
		if (i != temp)
			swap(sort[i], sort[temp]);
	}
}

template<typename T>
void BubbleSort(vector<T>& sort) {
	for (int i = sort.size() - 1; i > 0; --i) {
		for (int j = 1; j <= i; ++j) {
			if (sort[j] < sort[j - 1])
				swap(sort[j], sort[j - 1]);
		}
	}

}

template<typename T>
void InsertionSort(vector<T>& sort) {
	for (int i = 1; i < sort.size(); ++i) {
		for (int j = i; j >= 1 && sort[j - 1] > sort[j]; j--)
			swap(sort[j], sort[j - 1]);
	}
}

template<typename T>
void BinaryInsertionSort(vector<T>& sort) {
	for (int i = 1; i < sort.size(); i++) {
		int lower = 0;
		int upper = i - 1;
		T key = sort[i];
		while (lower <= upper) {
			int mid = (lower + upper) / 2;

			if (sort[mid] < key) {
				lower = mid + 1;
			}
			else
				upper = mid - 1;
		}

		for (int j = i; j > lower; j--)
			swap(sort[j], sort[j - 1]);
	}
}

template <typename T>
void ShelSort(vector<T>& sort) {
	for (int step = sort.size() / 2; step > 0; step /= 2) {
		for (int i = 0; i + step < sort.size(); i++) {
			for (int j = i + step; j < sort.size(); j += step) {
				if (sort[j] < sort[j - step])
					swap(sort[j], sort[j - step]);
			}
		}
	}
}

template <typename T>
void ShackerSort(vector<T>& sort) {
	int right = sort.size() - 1;
	int left = 0;
	while (left <= right) {
		for (int i = left; i < right; i++) {
			if (sort[i] > sort[i + 1])
				swap(sort[i], sort[i + 1]);
		}
		--right;
		for (int i = right; i > left; i--)
			if (sort[i] < sort[i - 1])
				swap(sort[i], sort[i - 1]);
		++left;
	}
}


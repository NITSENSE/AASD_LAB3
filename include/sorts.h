#pragma once
#include <vector>
#include <iostream>
#include "stats.h"
using namespace std;


template<typename T>
Stats SelectionSort(vector<T>& sort) {
	Stats stats;
	for (int i = 0; i < sort.size(); ++i) {
		int temp = i;
		for (int j = i; j < sort.size(); ++j) {
			stats.comparison_count++;
			if (sort[temp] > sort[j])
				temp = j;
		}
		stats.comparison_count++;
		if (i != temp) {
			swap(sort[i], sort[temp]);
			stats.copy_count += 2;
		}
	}
	return stats;
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
Stats ShelSort(vector<T>& sort) {
	Stats stats;
	int n = sort.size();
	int gap = n / 2;

	while (gap > 0) {
		for (int i = gap; i < n; ++i) {
			int temp = sort[i];
			int j = i;
			stats.comparison_count++;
			while (j >= gap && sort[j - gap] > temp) {
				stats.comparison_count++;
				stats.copy_count+=2;
				sort[j] = sort[j - gap];
				j -= gap;
			}
			sort[j] = temp;
		}
		gap /= 2;
	}
	/*for (int step = sort.size() / 2; step > 0; step /= 2) {
		for (int i = 0; i + step < sort.size(); i++) {
			for (int j = i + step; j < sort.size(); j += step) {
				stats.comparison_count++;
				if (sort[j] < sort[j - step])
					stats.copy_count += 2;
					swap(sort[j], sort[j - step]);
			}
		}
	}*/
	return stats;
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

template <typename T>
void QuickSort(vector<T>& sort, int low, int hight) {
	int left = low;
	int right = hight;

	int pivot = (left + right) / 2;

	while (left <= right) {
		while (sort[left] < sort[pivot])
			++left;
		while (sort[right] > sort[pivot])
			--right;
		if (left <= right) {
			swap(sort[left], sort[right]);
			left++;
			right--;
		}
		QuickSort(sort, low, right);
		QuickSort(sort, left, hight);
	}
}

template <typename T>
void CombSort(vector<T>& sort) {
	const double factor = 1.247;
	int step = (sort.size() - 1) / factor;
	while (step >= 1) {
		for (int i = step; i < sort.size(); i++) {
			if (sort[i] < sort[i - step])
				swap(sort[i], sort[i - step]);
		}
		step /= factor;
	}
}

template<typename T>
void Merge(vector<T>& sort, int left, int mid, int right, Stats& stat) {

	size_t i = left; 
	size_t j = mid + 1; 

	vector<T> temp; 

	while (i <= mid && j <= right) {
		stat.comparison_count++;
		if (sort[i] < sort[j]) {
			temp.push_back(sort[i++]);
			stat.copy_count++;
		}
		else {
			temp.push_back(sort[j++]);
			stat.copy_count++;
		}
	}
	while (i <= mid) {
		temp.push_back(sort[i++]);
		stat.copy_count++;
	}

	while (j <= right) {
		temp.push_back(sort[j++]);
		stat.copy_count++;
	}

	for (size_t i = left; i <= right; ++i) {
		sort[i] = temp[i - left];
		stat.copy_count++;
	}
}

template<typename T>
void MergeSort(vector<T>& sort, int left, int right, Stats& stat) {
	if (left < right) {
		size_t mid = left + (right - left) / 2;
		MergeSort(sort, left, mid, stat);
		MergeSort(sort, mid + 1, right, stat);

		Merge(sort, left, mid, right, stat);
	}
}

template<typename T>
Stats NatureMergeSort(vector<T>& sort) {
	Stats stat;
	MergeSort(sort, 0, sort.size() - 1, stat);
	return stat;
}


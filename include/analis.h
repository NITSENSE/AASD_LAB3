#pragma once
#include "stats.h"
#include "generate_arr.h"
#include "sorts.h"

Stats AverageStats(int lower_bound, int upper_bound, size_t size, size_t num_arr, Stats(*SortingFunction)(std::vector<int>& arr)) {
	Stats aver_stat;

	for (size_t i = 0; i < num_arr; ++i) {
		std::vector<int> arr_i = RandomArray(lower_bound, upper_bound, size);
		aver_stat += SortingFunction(arr_i);
	}

	aver_stat /= num_arr;
	return aver_stat;
}

void GetStats(int lower_bound, int upper_bound, size_t num_arr, const std::vector<size_t>& arr_len, Stats(*SortingFunction)(std::vector<int>& arr)) {
	for (int i = 0; i < arr_len.size(); ++i) {
		Stats stat = AverageStats(lower_bound, upper_bound, arr_len[i], num_arr, SortingFunction);
		std::cout << "Average Lenth: " << arr_len[i] << std::endl;
		std::cout << "Average Comparison count: " << stat.comparison_count << std::endl;
		std::cout << "Average Copy count: " << stat.copy_count << "\n" << std::endl;
	}
	std::cout <<"_________________________________________" << std::endl;
}

void GetStatsSortArr(const std::vector<size_t>& arr_len, std::vector<int>(*GenerateFunction)(size_t length), Stats(*SortingFunction)(std::vector<int>& arr)) {
	for (size_t i = 0; i < arr_len.size(); ++i) {
		std::vector<int> arr = GenerateFunction(arr_len[i]);
		Stats stat = SortingFunction(arr);
		std::cout << "Lenth: " << arr_len[i] << std::endl;
		std::cout << "Comparison count: " << stat.comparison_count << std::endl;
		std::cout << "Copy count: " << stat.copy_count << "\n" << std::endl;
	}
	std::cout << std::endl;
}
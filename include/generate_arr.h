#pragma once
#include <random>
#include <iostream>
#include <vector>


std::vector<int> RandomArray(int lower_bound, int upper_bound, size_t size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);

    std::vector<int> random_arr;
    random_arr.reserve(size);

    for (size_t i = 0; i < size; ++i) {
        random_arr.push_back(distribution(gen));
    }

    return random_arr;
}


std::vector<int> SortedArray(size_t size) {
    std::vector<int> sorted_array;
    for (size_t i = 1; i <= size; ++i) {
        sorted_array.push_back(i);
    }
    return sorted_array;
}


std::vector<int> ReverseSortedArray(size_t size) {
    std::vector<int> reverse_array;
    for (size_t i = size; i > 0; --i) {
        reverse_array.push_back(i);
    }
    return reverse_array;
}
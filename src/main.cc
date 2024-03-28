
#include "../include/sorts.h"
#include "../include/generate_arr.h"
#include "../include/analis.h"

template<typename T>
void printArr(std::vector<T> arr) {
	for (T num : arr) {
		std::cout << num << ' ';
	}
}

using namespace std;
int main() {
	/*std::vector<int> arr{ 1, 4, 7, 3, 9, 8, 5, 6, 2};
	printArr(arr);
	std::cout << std::endl;
	nTWMergeSort(arr);
	printArr(arr);

	cocktailSort(arr);
	printArr(arr);*/

	vector<size_t> lens_arr = { 1000, 2000, 3000, 4000, 5000, 10000, 25000, 50000 };
	int lower_bound = 1;
	int upper_bound = 50000;
	size_t num = 100;

	cout << "Statistics of the sorted array for selection sorting" << endl;
	GetStatsSortArr(lens_arr, SortedArray, SelectionSort);
	cout << "Statistics of the sorted array for shell sorting" << endl;
	GetStatsSortArr(lens_arr, SortedArray, ShelSort);
	cout << "Statistics of the sorted array for nature merge sorting" << endl;
	GetStatsSortArr(lens_arr, SortedArray, NatureMergeSort);
	cout << "Statistics of  back-sorted array for selection sorting" << endl;
	GetStatsSortArr(lens_arr, ReverseSortedArray, SelectionSort);
	cout << "Statistics of a back-sorted array for shell sorting" << endl;
	GetStatsSortArr(lens_arr, ReverseSortedArray, ShelSort);
	cout << "Statistics of a back-sorted array for merge sorting" << endl;
	GetStatsSortArr(lens_arr, ReverseSortedArray, NatureMergeSort);
	cout << "Statistics for selection sorting" << endl;
	GetStats(lower_bound, upper_bound, num, lens_arr, SelectionSort);
	cout << "Statistics for shell sorting" << endl;
	GetStats(lower_bound, upper_bound, num, lens_arr, ShelSort);
	cout << "Statistics for merge sorting" << endl;
	GetStats(lower_bound, upper_bound, num, lens_arr, NatureMergeSort);
}
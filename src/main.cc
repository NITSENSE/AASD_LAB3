
#include "../include/sorts.h"
#include "../include/generate_arr.h"
#include "../include/analis.h"
#include "../include/Students.h"

template<typename T>
void printArr(std::vector<T> arr) {
	for (T num : arr) {
		std::cout << num << ' ';
	}
}

using namespace std;
int main() {
	vector<string> str = { "book", "program", "ocean", "Tea", "loop", "slow", "growth", "apps" };
	printArr(str);
	cout << endl;
	Stats stat = NatureMergeSort(str);
	printArr(str);
	cout << endl;
	vector<Students> students = { Students("Natasha", 2), Students("Vova", 3), Students("Misha", 1), Students("Petia", 2), Students("Sonya", 5) };
	cout << students;
	Stats stats = SelectionSort(students);
	cout << students;
	stats.print();
	cout << "_________________________________________________________________" << endl;

	/*_________________________________________________________________________________*/

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
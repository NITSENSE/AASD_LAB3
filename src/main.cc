#include "../include/sorts.h"

int main() {
	vector<int> a = { 9, 8,7,6,5,4,3,2,1 };
	SelectionSort(a);
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
}

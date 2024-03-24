#include "../include/sorts.h"

int main() {
	vector<int> a = { 9, 8,7,6,5,4,3,2,1, 2346,264,3,6,456,21,674,2,46232,3467,23 };
	BubbleSort(a);
	for (int i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
}

#include <iostream>
#include <vector>

void bsort(std::vector<int> &arr) {
	bool swapped;
	for (int i = 0; i < arr.size()-1;i++) {
		for (int j = 0; j < arr.size() - i-1; j++) {
			if (arr[j]>arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}

int main4() {
	std::vector<int> arr = { 34,56,12,3,345 };
	bsort(arr);

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
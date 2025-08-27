#include <iostream>
#include <vector>

void isort(std::vector<int> &arr) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

int main() {
	std::vector<int> arr = { 34,54,12,1,23 };

	isort(arr);

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
}
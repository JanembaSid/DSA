#include <iostream>
#include <vector>

void ssort(std::vector<int>& arr) {
	for (int i = 0; i < arr.size()-1; i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;

	}
}

int main3() {
	std::vector<int> arr = {11,12,6,2,1};
	ssort(arr);
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}
#include <iostream>
#include <vector>

void merge(std::vector <int>& arr, int low, int mid, int high) {
	std::vector<int> temp;
	int left = low;
	int right = mid + 1;
	while (left <= mid && right <= high) {
		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			right++;
		}
	}
	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}

	while (right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	for (int i = low; i <= high; i++) {
		arr[i] = temp[i - low];
	}
}

void mS(std::vector <int>& arr, int low, int high) {
	if (low == high) return;
	int mid = (low + high) / 2;

	mS(arr, low, mid);
	mS(arr, mid + 1, high);
	merge(arr, low, mid, high);
}





int main() {
	const int n = 5;
	std::vector <int> arr = { 34,555,2,13,1 };
	mS(arr, 0, 4);
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
}
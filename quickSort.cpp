#include <iostream>
#include <vector>
int pivot(std::vector<int> &arr, int low, int high) {
	int pivot = arr[low];
	int i = low;
	int j = high;

	while (i < j) {
		while (arr[i] <= pivot && i <= high-1) {
			i++;
		}

		while (arr[j] > pivot && j >= low) {
			j--;
		}

		if(i<j) std::swap(arr[i], arr[j]);
		
	}
	std::swap(arr[low], arr[j]);
	return j;
}

void qsort(std::vector<int> &arr,int low, int high) {
	if (low<high) {
		int pIndex = pivot(arr,low,high);
		qsort(arr, low, pIndex - 1);
		qsort(arr, pIndex + 1, high);
	}
}



int main() {
	std::cout << "Enter a number: ";
	int n,m{};
	std::cin >> n;
	std::vector <int> arr;
	for (int i = 0; i < n; i++) {
		std::cout << "Enter a number to input in the array: ";
		std::cin >> m;
		arr.push_back(m);
	}

	qsort(arr,0,n-1);

	for (int j = 0; j < n; j++) {
		std::cout<< arr[j]<< " ";
	}
	return 0;
}

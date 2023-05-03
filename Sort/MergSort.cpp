#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& out, pair<int*,int> arr){
 for (int i = 0; i < arr.second; out << arr.first[i++] << " ");
 return out;            
}

std::istream& operator>>(std::istream& in, pair<int*,int> arr){
 for (int i = 0; i < arr.second; in >> arr.first[i++]);
 return in;            
}

void merge(int array[], int const left, int const mid, int const right){
	int const left_array_size = mid - left + 1, right_array_size = right - mid;
	int *left_array = new int[left_array_size], *right_array = new int[right_array_size];
 int left_array_index = 0, right_array_index = 0, index = left;

	for (int i = 0; i < right_array_size; i++){
  left_array[i] = array[left + i];
  right_array[i] = array[mid + 1 + i];
 }
 if (right_array_size < left_array_size) left_array[left_array_size -1] = array[left + left_array_size -1];

	while (left_array_index < left_array_size && right_array_index < right_array_size){
		if (left_array[left_array_index] <= right_array[right_array_index]) array[index++]	= left_array[left_array_index++];
  else array[index++] = right_array[right_array_index++];
	}

	while (left_array_index < left_array_size) array[index++] = left_array[left_array_index++];
 delete[] left_array;
	while (right_array_index < right_array_size) array[index++] = right_array[right_array_index++];
	delete[] right_array;
}

void mergeSort(int array[], int const begin, int const end){
	if (end <= begin) {return;} 
	mergeSort(array, begin, (begin + end)/2);
	mergeSort(array, (begin + end)/2 + 1, end);
	merge(array, begin, (begin + end)/2, end);
}

int main(){
 cout << "Array Size: ";
 int arr_size = 0;
 cin >> arr_size;

 cout << "Input array: ";
	int *arr = new int[arr_size];
 cin >> make_pair(arr,arr_size);

 mergeSort(arr, 0, arr_size-1);
	cout << "Sorted array is: " << make_pair(arr,arr_size);

	return 0;
}
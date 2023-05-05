#include <iostream>
#include <cmath>

using namespace std;

std::ostream &operator<<(std::ostream &out, pair<int *, int> arr){
 for (int i = 0; i < arr.second; out << arr.first[i++] << " ");
 return out;
}

std::istream &operator>>(std::istream &in, pair<int *, int> arr){
 for (int i = 0; i < arr.second; in >> arr.first[i++]);
 return in;
}

void InsertionSort(int arr[], int *begin, int *end){
 int left = begin - arr, right = end - arr;

 for (int i = left + 1; i <= right; i++){
  int key = arr[i], j = i - 1;
  while (j >= left && arr[j] > key){
   arr[j + 1] = arr[j];
   j--;
  }
  arr[j + 1] = key;
 }
}

int *Partition(int arr[], int low, int high){
 int pivot = arr[high], i = (low - 1);

 for (int j = low; j <= high - 1; j++){
  if (arr[j] <= pivot) swap(arr[++i], arr[j]);
 }
 swap(arr[i + 1], arr[high]);
 return (arr + i + 1);
}

int *MedianOfThree(int *a, int *b, int *c){
 if ((*b <= *a && *a < *c) || (*c <= *a && *a < *b)) return (a);
 if ((*a < *b && *b < *c) || (*c <= *b && *b <= *a)) return (b);
 return (c);
}

void IntrosortUtil(int arr[], int *begin, int *end, int depthLimit){
 int size = end - begin;

 if (size < 16){
  return InsertionSort(arr, begin, end);
 }

 if (depthLimit == 0){
  make_heap(begin, end + 1);
  sort_heap(begin, end + 1);
  return;
 }

 swap(*MedianOfThree(begin, begin + size / 2, end), *end);

 int *partitionPoint = Partition(arr, begin - arr, end - arr);
 IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
 IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
 return;
}

void Introsort(int arr[], int *begin, int *end){
 int depthLimit = 2 * log(end - begin);
 return IntrosortUtil(arr, begin, end, depthLimit);
}

int main(){
 cout << "Array Size: ";
 int arr_size = 0;
 cin >> arr_size;

 cout << "Input array: ";
 int *arr = new int[arr_size];
 cin >> make_pair(arr, arr_size);

 Introsort(arr, arr, arr + arr_size - 1);
 cout << "Sorted array is: " << make_pair(arr, arr_size);
 return (0);
}

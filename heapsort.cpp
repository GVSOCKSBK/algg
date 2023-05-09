#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
   int temp;
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < n && arr[l] > arr[largest])
      largest = l;
   if (r < n && arr[r] > arr[largest])
      largest = r;
   if (largest != i) {
      temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
   }
}

void heapSort(int arr[], int n) {
   int temp;
   for (int i = n ; i >= 0; i--)
      heapify(arr, n, i);
   for (int i = n - 1; i >= 0; i--) {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, i, 0);
   }
}

int main() {
   int n;
   cout << "Enter number of elements: ";
   cin >> n;
   int arr[n];
   int i;
   cout << "\nEnter the data elements: ";
   for (i = 0; i < n; i++)
       cin >> arr[i];
   cout<<"Given array is: "<<endl;
   for (i = 0; i < n; i++)
       cout<<arr[i]<<" ";
   cout<<endl;
   heapSort(arr, n);
   cout << "\nSorted array is: \n";
   for (i = 0; i < n; ++i)
       cout<<arr[i]<<" ";
}
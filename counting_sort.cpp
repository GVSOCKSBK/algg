#include <iostream>

 using namespace std;

void display(int arr[], int size) 
 {
   for (int i = 0; i < size; i++)

    cout << arr[i] << " ";

    cout << "\n";
 }

void count_sort(int array[], int size) 
{
  int output[size];
  int max = array[0];

  for (int i = 1; i < size; i++)
   {
      if (array[i] > max)
          max = array[i];
   }

  int count[max + 1] = {0} ;

  for (int i = 0; i < size; i++) 
   {
       count[array[i]]++;
   }

  for (int i = 1; i <= max; i++) 
   {
       count[i] += count[i - 1];
   }

  for (int i = size - 1; i >= 0; i--) 
   {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
   }

  for (int i = 0; i < size; i++) 
   {
       array[i] = output[i];
   }

}

int main()
 {
  
  int n ;
  
  cout << "\nEnter the Number of Elements: ";
  cin >> n;
        
  int arr[n] ;

  cout << "\nEnter the Elements: ";
          
  for (int i = 0; i < n; i++) 
   
      cin >> arr[i] ;

  cout << "\nArray before Sorting: ";
                   
  display(arr, n);

  count_sort(arr, n) ;

  cout << "\nArray After Count Sorting: ";
                    
  display(arr, n);
     
  return 0;
 }
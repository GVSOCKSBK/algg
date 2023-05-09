#include <cstdlib>
#include <iostream>
#include <time.h>

  using namespace std;

int count = 0 ;

void display(int arr[], int size) 
 {
   for (int i = 0; i < size; i++)

		cout << arr[i] << " ";

    cout << "\n";
 }

int partition(int arr[], int p, int r)
{
	int x = arr[r]; 

	int i = (p - 1); 

	for (int j = p; j <= r - 1; j++) 
	{
		if (arr[j] <= x) 
		{
			i++; 
			swap(arr[i], arr[j]);
			count++ ;
		}
	}

	swap(arr[i + 1], arr[r]);
	
	return (i + 1);
}

int randomized_partition(int arr[], int p, int r)
{
	srand(time(NULL));
	
	int random = p + rand() % (r - p);

	swap(arr[random], arr[r]);

	return partition(arr, p, r);
}

int randomized_select(int A[], int p, int r, int i)
{
	if (p == r)
		return A[p] ;

	int q = randomized_partition(A,p,r) ;
	int k = q - p + 1 ;

    if (i == k)
    	return A[q] ;

    else if (i < k)
    	return randomized_select(A, p, q-1, i) ;

    else
    	return randomized_select(A, q + 1, r, i - k) ;
}

int main()
 {
  
  int n, i ;
 
  cout << "\t\t RANDOMIZED SELECT \n" ;	
  cout << "\nEnter the Number of Elements: ";
  cin >> n;
		    
  int arr[n] ;

  cout << "\nEnter the Elements: ";
					
  for (int i = 0; i < n; i++) 
	 
      cin >> arr[i] ;

  cout << "\nArray : ";
                   
  display(arr, n);

  cout << "\n Enter which smallest element you want ? " ;
  cin >> i ;

  cout << "\n " << i << " smallest element : " << randomized_select(arr, 0, n - 1, i) ;
                         
 	return 0;
 }
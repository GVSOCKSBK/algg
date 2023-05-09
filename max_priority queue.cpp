#include <iostream>

 using namespace std ;

void swap(int * a, int * b) 
 {
     int temp = * a;
     * a = * b;
     * b = temp;
 }


void max_heapify(int arr[], int n, int i)
 {
  int largest = i; 
  int l = 2 * i + 1; 
  int r = 2 * i + 2; 

  if (l < n && arr[l] > arr[i])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) 
   {
    swap(arr[i], arr[largest]);
    max_heapify(arr, n, largest);
   }

 }

void build_maxheap(int arr[], int n)
 {
   for (int i = n / 2 - 1; i >= 0; i--)
       max_heapify(arr, n, i) ;
 }

int heap_maximum(int arr[])
{
	return arr[0] ;
}


int heap_exract_max(int arr[],int *heap_size)
{
   if (*heap_size < 0)
   {
      cout << "\n\n Heap Underflow" ;
      return -100 ;
   }

   int max = arr[0] ;

   swap(arr[0],arr[*heap_size - 1]) ;

   *heap_size = *heap_size - 1 ;

   int j = *heap_size ;

   max_heapify(arr, j, 0) ;

   return max ;
}

 void heap_increase_key(int arr[], int i, int key)
 {
    if (key < arr[i])
     {
        cout<<"\n\n Error :  new key is smaller than current value " << endl ;
        return ;
     }
     
    arr[i] = key;
  
    int parent = (i-1)/2;
  
    while(i > 0 && arr[parent] < arr[i])
     {
         swap(arr[i], arr[parent]);
         i = parent;
         parent = (i-1)/2;
     }

}

void Max_heap_Insert(int arr[], int key, int *heapsize)
{
   *heapsize = *heapsize + 1 ;

   arr[*heapsize-1] = -999999 ;

   heap_increase_key(arr, *heapsize-1, key) ;
}

void display(int arr[], int size) 
 {
   for (int i = 0; i < size; i++)

		cout << arr[i] << " ";

    cout << "\n";
 }

int main()
{
  	int n, choice ;

    cout<<"\n\n Enter the size of the array : " ;

    cin>>n ;

    int arr[n] ;

    cout<<"\n\n Enter the element in the array : "<<endl ;

    for(int i=0; i<n; i++)
    {
       cin >> arr[i];
    }

     build_maxheap(arr, n) ;


  	do{                                     // do - while loop for MENU 

  	  cout<<"\n\n\t\t\t MAIN MENU \n\n"
  	      <<"\n \"1\" Heap Maximum ."
  	      <<"\n \"2\" Heap Extract Maximum ."
  	      <<"\n \"3\" Heap Increase Key ."
  	      <<"\n \"4\" Max Heap Insert ." 
  	      <<"\n \"5\" Display ." 
  	      <<"\n \"6\" EXIT ." ;
  	  
  	 cout<<"\n\n\t\t Enter Your Choice : ";

  	 cin>>choice ;

  	   while(!(choice >= 1 && choice <= 6))       // this loop checks for input to be between 1 and 6
  	      {
  	   
  	         cout<<"\n\t\t INVALID INPUT !!!"<<"\n\n Please Enter a Valid Input : ";

  	                 cin>>n ;

  	      }    

  	 
  	    switch(choice)
  	      {

  	           case 1 : {
  	                        
                          cout<<"\n\n Maximum Number in the heap : " << heap_maximum(arr) << endl ;

                           display(arr, n) ;

                            break ;
  	
  	                    }
  	         
  	           case 2 : {
  	                        int num = heap_exract_max(arr, &n);
                          
                            if ( num != -100)
                              
                              cout<<"\n\n Extracted Maximum no. in the heap "<< num <<endl;
                             
                             display(arr, n) ;

  	                          break ; 
  	                        
  	                    }

  	           case 3 : {

  	                        int key,index;
                            
                            cout << "\n\n Enter the new key : ";
                            cin >> key;
                            cout << "Enter the index : "<<endl;
                            cin >> index;
                            
                            heap_increase_key(arr, index, key);
                           
                             display(arr, n) ;

  	                           break ;

  	                    }

  	           case 4 : {

  	                        int key ;
                            
                            cout << "\n\n Enter the new key : ";
                            cin >> key;

                            Max_heap_Insert(arr, key, &n);

                             display(arr, n) ;

  	                           break ;

  	                    }

  	           case 5 : {

  	                        display(arr, n) ;

  	                           break ;

  	                    }

  	           case 6 :    return 0 ;                                   

  	      }
  	               

  	  } while(true) ;       

	return 0;
}

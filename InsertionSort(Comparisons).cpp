#include <iostream> 
#include<iomanip>
#include<time.h>
using namespace std; 

class InsertionSort
{
	public: 
	
		InsertionSort(int n=0)
		{
			this->n=n;
			arr=new int[n];
		} //constructor
		~InsertionSort(){delete [] arr;}  //destructor
        void show();
		void input(int);
		void sort() ;
	private:
		 
		int n;       
		int *arr;
};

void InsertionSort::input(int n)
{
	
	for(int i=0;i<n;i++)
	{
		arr[i]=rand();
	}
}

void InsertionSort::show()
{
	for(int i=0;i<n;i++)
	{		
		cout<<setw(6)<<arr[i];
	}
}

void InsertionSort::sort() 
{
	int count=0,j;

	for (int i = 1; i < n; i++) 
	{
		
		int tmp = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>tmp)
		{
			arr[j+1] = arr[j];
			count++;
			j--;
		}
		if(!(arr[j]>tmp))
			count++;
		arr[j+1] = tmp;
	}

	cout<<setw(32)<<count;
}

int main() 
{ 
	int size,*arr;
	cout<<"********************************INSERTION SORT********************************"<<endl;
	srand(time(NULL));
	cout<<"\nUnsorted Array "<<setw(4)<<"\t\t\tSize of array "<<setw(7)<<"\t\t\tComparisons "<<setw(7);
	cout<<"\n------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<100;i++)
	{
		size=rand()%1000 + 1;		//29+1=30 acceptable
		if(size<30)
			size+=30;
		InsertionSort obj(size);
		obj.input(size);
		cout<<"\n"<<setw(9)<<i+1<<setw(31)<<size;
		obj.sort();

	}
	
} 

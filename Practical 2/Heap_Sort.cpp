#include <iostream>
using namespace std;

int heapsize,count=0;

int LEFT(int i)
{
	return 2*i+1;
}
int RIGHT(int i)
{
	return 2*i+2;
}

void max_heapify(int arr[], int n, int i)
{
    int largest=i;
    int l = LEFT(i);
    int r = RIGHT(i);

    if (l <heapsize)
	{
		count++;
		if(arr[l] >arr[largest])
	        largest = l;
		else
		largest = i;
	}
    else
	{
       largest = i;
	}
    if (r <heapsize )
	{
		count++;
		if(arr[r] >arr[largest])
	      largest = r;
	}
    if (largest != i) {

	    int temp;
        temp=arr[i];
arr[i]=arr[largest];
arr[largest]=temp;

	max_heapify(arr, n, largest);
    }
}
void Build_max_heap(int arr[],int n)
{
	heapsize=n;
	int i=n/2;
	for (i=i-1 ;i>= 0; i--)
	{
	max_heapify(arr, n, i);
	}
}

void heapSort(int arr[], int n)
{
Build_max_heap(arr,n);
    for (int i = n-1 ;i>= 1; i--)
	{
        int temp;
        temp=arr[0];
arr[0]=arr[i];
arr[i]=temp;

	heapsize=heapsize-1;
max_heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
cout<<" {";
    for (int i = 0; i< n; ++i)
cout<<arr[i] << " ";
cout<<"}\n";
}
int main()
{
    int arr[20];
    int n;
cout<<"Enter the size of the array:- ";
cin>>n;
heapsize=n;
cout<<"\nEnter the elements:- \n ";
for(int i=0; i<n; i++)
    {
cin>>arr[i];
	}

heapSort(arr, n);

cout<< "\nSORTED ARRAY USING HEAP SORT
:-  \n";
printArray(arr, n);

	cout<< "\nTOTAL NUMBER OF COMPARISONS :- "<<count;
    return 0;
}

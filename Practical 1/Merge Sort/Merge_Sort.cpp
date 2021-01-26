#include<iostream>
#include<stdio.h>

using namespace std;

int count = 0; //count of comparisons
int n = 0;
const int MAX_ITEMS = 100;
void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast);
void printarray( int a[], int n);
void mergesort(int a[], int start, int end)
{  //no significant comparisons are done during splitting

    if(start < end)
    {
        int mid = (start+end)/2;
        mergesort(a,start, mid);
        mergesort(a,mid+1,end);
        merge(a, start,mid, mid+1, end);
    }
}

void merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
        int temparray[MAX_ITEMS];
        int index = leftFirst;
        int saveFirst = leftFirst;

        while((leftFirst <= leftLast)  && ( rightFirst <= rightLast))
    {  //compare and select smallest from two subarrays

            if(values[leftFirst] < values[rightFirst]){
                temparray[index]  = values[leftFirst]; //smallest assigned to temp
                leftFirst++;
            }
            else
            {
                temparray[index]  = values[rightFirst];
                rightFirst++;
            }
            index++;
            count++;  //count of comaparisons done during merge. One comparison is done per iteration of while loop.
        }

        while(leftFirst <= leftLast)
     {

            temparray[index] = values[leftFirst];
            leftFirst++;
            index++;

        }
        while(rightFirst <= rightLast){
            temparray[index] = values[rightFirst];
            rightFirst++;
            index++;
        }

        for(index = saveFirst; index <= rightLast; index++)//copies from temp array to values array
        values[index] = temparray[index];
        cout<<endl<<"Array after every pass: ";
        printarray(values,n);

    }

void printarray( int a[], int n)
{
    for (int i=0; i < n; i++)
        cout<<a[i]<<"  ";
        cout<<"\n----------------------------------------------------------------\n";
}

int main()
{
    cout<<"Enter the number of  elements to be sorted : ";
    cin>>n;

    int a[MAX_ITEMS];
    for (int i=0; i < n; i++)
    {
        if(i==0)
            cout<<"Enter the first element: ";
        else
            cout<<"Enter the next element: ";
        cin>>a[i];
    }

    int start = 0;
    int end = n-1;
    mergesort(a, start, end);
    cout<<"SORTED ARRAY (USING MERGE SORT) : ";
    printarray(a, n);
    cout<<endl;
    cout<<"\nTOTAL NUMBER OF COMPARISONS : "<<count<< endl;
}

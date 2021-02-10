#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#define MIN_SIZE 30
#define MAX_SIZE 1000

using namespace std;

int comparisons = 0;

int heapSort(int*, int);
int Build_max_heap(int,int);
int max_heapify(int , int , int );

int main()
{
    try
    {
        srand(time(0));

        int size;
        int array[MAX_SIZE];

        ofstream fout("./results.csv");
        cout << "+----------------------------------------------------+\n";
        cout << "| Input Size | Best Case | Average Case | Worst Case |\n";
        cout << "+----------------------------------------------------+\n";

        fout << "size,best,avg,worst\n";

        for (int i = 0; i < 100; i++)
        {
            // rand() % (upperBound + 1 - lowerBound) + lowerBound
            size = rand() % (MAX_SIZE + 1 - MIN_SIZE) + MIN_SIZE;

            // Input Size
            cout << "| " << setw(10) << size;
            fout << size << ",";

            // Best Case
            for (int i = 0; i < size; i++)
                array[i] = i + 1;
            comparisons = heapSort(array,  size - 1);
            cout << " | " << setw(9) << right << comparisons;
            fout << comparisons << ",";

            // Average Case
            try
            {
                ifstream fin("./random.txt");
                for (int i = 0; i < size; i++)
                    fin >> array[i];
                fin.close();
                comparisons = heapSort(array,  size - 1);
                cout << " | " << setw(12)<<right  << comparisons;
                fout << comparisons << ",";
            }
            catch (exception e)
            {
                cerr << e.what();
                return -1;
            }

            // Worst Case
            for (int i = 0; i < size; i++)
                array[i] = size - i;
          int  comparisons = heapSort(array,  size - 1);
            cout << " | " << setw(10)<<right  << comparisons << " |\n";
            fout << comparisons << "\n";
        }

          cout<<"+----------------------------------------------------+\n\n";

        fout.close();

        return 0;
    }
    catch (exception e)
    {
        cerr << e.what();
        return -1;
    }
}

int heapsize;

int LEFT(int i)
{
	return 2*i+1;
}
int RIGHT(int i)
{
	return 2*i+2;
}

int max_heapify(int arr[], int n, int i)
{
    int largest=i;
    int l = LEFT(i);
    int r = RIGHT(i);

    if (l <heapsize)
	{
		comparisons++;
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
		comparisons++;
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
 return comparisons;
}

int Build_max_heap(int arr[],int n)
{
	heapsize=n;
	int i=n/2;
	for (i=i-1 ;i>= 0; i--)
	{
	max_heapify(arr, n, i);
	}
	return comparisons;
}

int heapSort(int arr[], int n)
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
  return comparisons;
}






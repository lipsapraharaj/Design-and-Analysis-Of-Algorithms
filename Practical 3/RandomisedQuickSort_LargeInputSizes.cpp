#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#define MIN_SIZE 30
#define MAX_SIZE 1000

using namespace std;

int comparisons = 0;

int R_Quicksort(int*,int,int );
int R_Partition(int*,int,int);
int Partition(int*,int,int);

int main()
{
    try
    {
        srand(time(0));

        int size;
        int array[MAX_SIZE];

        ofstream fout("./results.csv");

        cout << "+-----------------------------------------------------+\n";
        cout << "| Input Size | Best Case | Average Case | Worst Case  |\n";
        cout << "+-----------------------------------------------------+\n";
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
            comparisons = R_Quicksort(array, 0, size - 1);
            cout << " | " << setw(9) << right << comparisons;
            fout << comparisons << ",";

            // Average Case
            try
            {
                ifstream fin("./random.txt");
                for (int i = 0; i < size; i++)
                    fin >> array[i];
                fin.close();
                comparisons = R_Quicksort(array, 0, size - 1);
                cout << " | " << setw(12) << right << comparisons;
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
            comparisons = R_Quicksort(array, 0, size - 1);
            cout << " | " << setw(11) << right << comparisons << " |\n";
            fout << comparisons << "\n";
        }

        cout << "+-----------------------------------------------------+\n\n";

        fout.close();

        return 0;
    }
    catch (exception e)
    {
        cerr << e.what();
        return -1;
    }
}


int R_Quicksort(int a[],int p,int r)
    {
        int q;
        if(p<r)
        {
         q=R_Partition(a,p,r);
         R_Quicksort(a,p,q-1);
         R_Quicksort(a,q+1,r);
        }
    }

 int R_Partition(int a[],int p,int r)
 {
        int i=p+rand()%(r-p+1);
        int temp;
        temp=a[r];
        a[r]=a[i];
        a[i]=temp;
        return Partition(a,p,r);
  }

 int Partition(int a[],int p,int r)
 {
        int temp,temp1;
        int x=a[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++)
        {
            comparisons++;
            if(a[j]<=x)
            {

                i=i+1;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp1=a[i+1];
        a[i+1]=a[r];
        a[r]=temp1;
        return i+1;

  }

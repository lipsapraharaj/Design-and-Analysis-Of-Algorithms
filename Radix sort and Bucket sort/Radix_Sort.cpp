#include<iostream>
using namespace std;
int getmax(int a[],int n)
{
    int max=a[0];
for(int x=1; x<n; x++)
    {

         if(a[x]>max)
            max=a[x];
            return max;

    }
}
void countsort(int a[],int n,int exp)
{
    int result[n],i,count[10]={0};
for(int i=0;i<n;i++)
        count[(a[i] /exp)%10]++;
    for(i=1;i<10;i++)
        count[i] +=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        result[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp )%10]--;
}
for(i=0;i<n;i++)
{
    a[i]=result[i];

}
    }


void radixsort(int a[],int n)
{
   int exp,i;
i=getmax(a,n);
for(exp=1; i/exp>0; exp*=10)
   {

countsort(a,n,exp);
   }
}
int main()
{
    int n;
cout<<"Enter the number of elements to be sorted: ";
cin>>n;
    int a[n];
cout<<"Enter the elements: "<<endl;
for(int i=0;i<n;i++)
    {
cin>>a[i];

    }
radixsort(a,n);
cout<<"\nSORTED LIST USING RADIX SORT: "<<endl;
cout<<"{ ";
for(int i =0;i<n;i++)
cout<<a[i]<<" ";
cout<<" } ";
}

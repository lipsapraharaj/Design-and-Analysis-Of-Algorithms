# include<iostream>
using namespace std;
class insertion
{
	private:
		int arr[10];
		int n;
		public:
		void input();
		void display();
		void insertion_sort();

};
void insertion::input()
{
    int i;
	cout<<"Enter the size of the array:";
	cin>>n;
	cout<<"Enter the elements of the array:";
	for(i=0;i<n;i++)
   {
    cin>>arr[i];
   }
   insertion_sort();
}

void insertion::display()
{
	cout<<"The elements of the array are: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";

	}
}
void insertion::insertion_sort()
{
	int c,tc=0;
	for(int i=1;i<n;i++)
	{
		c=0;
		int j=i-1;
		int k=arr[i];
		while(j>=0&&k<arr[j])
		{
			arr[j+1]=arr[j];
			j=j-1;
			c=c+1;
		}
		arr[j+1]=k;
		cout<<endl<<"After pass "<<i<<endl;
		display();
		if(j<0)
		{
			cout<<endl<<"No. of comparisons = "<<c<<endl;
		}
		else
            {
			cout<<endl<<"No. of comparisons = "<<++c<<endl;

		}
		tc=tc+c;
	}
	cout<<"TOTAL NO. OF COMPARISONS = "<<tc<<endl;
}
int main()
{
	insertion ob1;
	ob1.input();
	ob1.display();
	return 0;
}

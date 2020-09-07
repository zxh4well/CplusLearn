#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int i,j;
	cout<<"    9 x 9 Multiplication Table\n";
	cout<<"---------------------------------------\n";
	cout<<"  ";
	for(i=1;i<=9;i++)
		cout<<setw(4)<<i;//crow title
	cout<<"\n";
	cout<<"---------------------------------------\n";
	//one by one print 
	//j==i the rect line
	//j<i under
	//j>i top
	for(i=1;i<=9;i++)
	{
		cout <<setw(2)<<i;
		for(j=1;j<=9;j++)
		{
			if(j<i)
				cout<<"    ";
			else 
				cout<<setw(4)<<i*j;
		}
		cout<<endl;
	}
	cout<<"--------------------------------------\n";
	return 0;
}

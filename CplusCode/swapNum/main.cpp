#include<iostream>

using namespace std;

int swap(int x,int y);

int main()
{
	int a,b;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	swap(a,b);
	cout<<"a:"<<a<<"  "<<"b:"<<b<<endl;
	return 0;
}

int swap(int x,int y)
{
	int temp;
	temp = x;
	x = y;
	y= temp;
	cout<<"x:"<<x<<"  "<<"y:"<<y<<endl;

}

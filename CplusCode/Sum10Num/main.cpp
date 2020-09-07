#include<iostream>

using namespace std;

int main()
{
	int a,sum=0;
	for(int i=0;i<10;i++){
		cout<<"num"<<i<<":";
		cin>>a;
		sum += a;
	}
	cout<<"sum "<<sum<<endl;

	return 0;
}

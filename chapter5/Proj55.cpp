#include<iostream>
using namespace::std;

int main()
{
	int s;
	char c;
	cin>>s;
	/*if(s<60)
		c='C';
	else if(s<=80)
		c='B';
	else
		c='A';*/

	c=s>60?s>=80?'A':'B':'C';
	cout<<c<<endl;

	return 0;
}

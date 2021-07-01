#include<iostream>

using namespace::std;
int main()
{
	int x[10],*p;
	p=x;
	cout<<sizeof(x)/sizeof(*x)<<endl;
	cout<<sizeof(p)/sizeof(*p)<<endl;

	return 0;
}

#include<iostream>

using namespace::std;
int main()
{
	int ia[10],ib[10];

	for(size_t i=0;i!=10;++i)
		ia[i]=i;
	for(size_t i=0;i!=10;++i)
		cout<<ia[i]<<" ";
	cout<<endl;
	for(size_t i=0;i!=10;++i)
		ib[i]=ia[i];
	for(size_t i=0;i!=10;++i)
		cout<<ib[i]<<" ";
	cout<<endl;

	return 0;
}

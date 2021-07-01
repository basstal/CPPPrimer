#include<iostream>
using namespace::std;
int main()
{
	int ia[10]={1,2,3,4,5,6,7,8,9,10};
	
	
	for(int *p = begin(ia);p!=end(ia);++p)
		*p=0;
	for(size_t i=0;i!=10;++i)
		cout<<ia[i]<<" ";
	cout<<endl;
	return 0;
}

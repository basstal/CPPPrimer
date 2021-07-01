#include<vector>
#include<iostream>
using namespace::std;


int main()
{
	vector<int> v{1,3,5,7,9};
	int sz[5];

	for(int i=0;i!=5;++i)
	{
		sz[i]=v[i];
		cout<<sz[i]<<" ";
	}
	return 0;
}

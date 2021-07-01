#include<vector>
#include<iostream>
using namespace::std;
int main()
{
	int sz[]={1,3,5,7,9};
	vector<int> v(begin(sz),end(sz));

	for(auto &w:v)
		cout<<w<<" ";
	return 0;
}

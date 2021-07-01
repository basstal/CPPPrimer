#include<iostream>
#include<vector>
using namespace::std;

int main()
{
	vector<int> v{1,2,3,4,5,6};
	

	for(auto &w:v)
	{
		w%2==1?w*=2:0;
		cout<<w<<" ";
	}

	return 0;
}

#include<vector>
#include<iostream>


using namespace::std;

int main()
{
	vector<int> v{0,1,2,3,4,5,6,7,8,9},va;
	va=v;
	for(auto &w:va)
		cout<<w<<" ";
	cout<<endl;
	return 0;
}

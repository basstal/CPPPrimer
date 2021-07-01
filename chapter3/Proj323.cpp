#include<vector>
#include<iostream>

using namespace::std;
int main()
{
	vector<int> vctI(10,8);
	
	for(auto it=vctI.begin();it!=vctI.end();++it)
		*it *= 2;
	for(auto &w:vctI)
		cout<<w<<" ";
	cout<<endl;
	return 0;
}

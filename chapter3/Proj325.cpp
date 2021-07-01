#include<vector>
#include<iostream>
using namespace::std;
int main()
{
	vector<unsigned> v(11,0);
	unsigned score;
	auto it = v.begin();	
	while(cin>>score)
		++*(it + score/10);
	for(auto &w:v)
		cout<<w<<" ";
	cout<<endl;

	return 0;
}	

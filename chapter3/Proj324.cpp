#include<vector>
#include<iostream>
using namespace::std;
int main()
{
	vector<int> v;
	int i;
	
	while(cin>>i)
	{
		v.push_back(i);
	}
	auto ia=v.begin();
	auto ib=v.begin()+1;
	while(ia!=v.end()&&ib!=v.end())
	{
		cout<<"ia+ib="<<*ia+*ib<<endl;
		ia+=2;ib+=2;
	}
	if(ia!=v.end())
	cout<<"ia="<<*ia<<endl;
	
	return 0;
}

#include<vector>
#include<list>
#include<string>
#include<iostream>
using namespace::std;

template<typename I,typename T>
I find(const I &begin,const I &end,const T &tar)
{
	auto iter=begin;
	while(iter!=end && *iter!=tar)++iter;
	return iter;
}

int main()
{
	vector<int> vec{2,5,8,11,13};
	list<string> il{"you","are","me"};

	cout<<*find(vec.cbegin(),vec.cend(),5)<<endl;
	cout<<*find(il.cbegin(),il.cend(),"see")<<endl;
	return 0;
}
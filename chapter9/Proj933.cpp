#include<list>
#include<iostream>

using namespace::std;
int main(){
	list<int> il{3,5,7,9};

	auto begin=il.begin();
	while(begin!=il.end()){
		++begin;
		il.insert(begin,42);
		++begin;
	}
	for(const auto &e:il)
		cout<<e<<" ";
	cout<<endl;

	return 0;
}
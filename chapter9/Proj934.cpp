#include<vector>
#include<iostream>

using namespace::std;

int main(){
	vector<int> v{1,3,2,5,9};

	auto iter=v.begin();
	while(iter!=v.end())
		if(*iter%2)
			iter=v.insert(iter,*iter);
	++iter;
	for(const auto &e:v)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}
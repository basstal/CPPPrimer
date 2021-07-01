#include"head.h"

int main(){
	vector<int> v{0,4,5,6,7,75,76,7,0,567};
	list<int> lis;
	auto rev_begin = v.rbegin()+3;
	auto rev_end = v.rend() -3;
	copy(rev_begin,rev_end,back_inserter(lis));
	for(const auto &e:lis)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}
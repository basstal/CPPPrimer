#include"head.h"


int main(){
	vector<int> src_vec{1,5,6,4534,6,45,4534,534,56,57,567,56,7,433,42,434};
	list<int> target;
	sort(src_vec.begin(),src_vec.end(),[](const int &a,const int &b){return a>b;});
	for(const auto &e:src_vec)
		cout<<e<<" ";
	cout<<endl;
	unique_copy(src_vec.begin(),src_vec.end(),inserter(target,target.begin()));
	for(const auto &see:target)
		cout<<see<<" ";
	cout <<endl;
	return 0;
}
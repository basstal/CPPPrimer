#include"head.h"

int main(){
	vector<int> num{1,2,3,4,5,6,7,8,9};
	list<int> lst;
	deque<int> deq;
	forward_list<int> flst;
	copy(num.begin(),num.end(),inserter(lst,lst.begin()));
	for(const auto &see:lst)
		cout << see << " ";
	cout <<endl;
	copy(num.begin(),num.end(),front_inserter(flst));
	for(const auto &see:flst)
		cout << see << " ";
	cout <<endl;
	copy(num.begin(),num.end(),back_inserter(deq));
	for(const auto &see:deq)
		cout << see << " ";
	cout <<endl;

	return 0;
}
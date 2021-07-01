#include<iostream>
#include<forward_list>
using namespace::std;
int main(){
	forward_list<int> intFlist{3,343,534,5,34,15,43,53,4532,45};
	forward_list<int>::iterator prev = intFlist.before_begin();
	forward_list<int>::iterator cur = intFlist.begin();

	while(cur!=intFlist.end()){
		if((*cur) %2==1)
			cur = intFlist.erase_after(prev);
		else{
			++cur;
			++prev;
		}
	}
	for(const auto &e:intFlist)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}
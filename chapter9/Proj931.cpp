#include<list>
#include<iostream>
#include<forward_list>
using namespace::std;
int main(){
	list<int> intl{1,2,3,4,5,6,7,8,9};
	auto iter = intl.begin();
	while(iter != intl.end()){
		if((*iter)%2 == 1){
			iter = intl.insert(iter,*iter);
			++iter;
			++iter;
		}else
			iter = intl.erase(iter);
	}
	for(const auto &e:intl)
		cout<<e<<" ";
	cout<<endl;

	forward_list<int> intfl{1,2,3,4,5,6,7,8,9};
	auto prev = intfl.before_begin();
	auto cur = intfl.begin();
	while(cur!=intfl.end()){
		if((*cur)%2 ==1){
			prev = intfl.insert_after(prev,*cur);
			++prev;
			++cur;
		}else{
			cur = intfl.erase_after(prev);
		}
	}
	for(const auto &e:intfl)
		cout<<e<<" ";
	cout<<endl;

	return 0;
}
/*
 * Proj926.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<vector>
#include<list>
#include<iostream>
using namespace::std;
int main(){
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> ve(begin(ia),end(ia));
	list<int> li(begin(ia),end(ia));
	list<int>::iterator it = li.begin();
	vector<int>::iterator itv = ve.begin();

	while(it!=li.end()){
		if((*it)%2==1){
			it = li.erase(it);
			continue;
		}
		++it;
	}
	for(const auto &e:li)
		cout<<e<<" ";
	cout<<endl;

	while(itv!=ve.end()){
		if((*itv)%2==0){
			itv = ve.erase(itv);
			continue;
		}
		++itv;
	}
	for(const auto &e:ve)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}



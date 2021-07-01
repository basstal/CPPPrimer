/*
 * Proj925.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<list>
#include<iostream>
using namespace::std;
int main(){
	list<int> li{3,6,8,9,24,77};
	list<int>::iterator it1 =li.begin();
	list<int>::iterator it2 = li.begin();
	li.erase(it1,it2);
	for(const auto &e:li)
		cout<<e<<" ";
	cout<<endl;
	it1=li.begin();
	li.erase(it1,li.end());
	for(const auto &e:li)
		cout<<e<<" ";
	cout<<endl;
	li.erase(li.end(),li.end());
	for(const auto &e:li)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}




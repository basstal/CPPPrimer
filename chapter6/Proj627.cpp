/*
 * Proj627.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */

#include<initializer_list>
#include<iostream>
using namespace::std;
int func(initializer_list<int>);
int main(){
	cout<<func({1,6,8,12,4})<<endl;
	return 0;
}
int func(initializer_list<int> lst){
	int sum=0;
	for(auto &e:lst)
		sum+=e;
	return sum;
}

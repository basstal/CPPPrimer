/*
 * Proj920.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<list>
#include<deque>
#include<iostream>
using namespace::std;
int main(){
	list<int> li{123,45,43,534,2534,5,34,53,464,56,456};
	deque<int> odds,evens;
	list<int>::iterator it = li.begin();
	while(it!=li.end()){
		(*it%2==0)?evens.push_back(*it):odds.push_back(*it);
		++it;
	}
	return 0;
}




/*
 * Proj66.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
int equal(int n){
	int val;
	static int cnt=0;
	if(cin>>val&&val==n)
		++cnt;
	return cnt;
}


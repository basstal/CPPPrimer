/*
 * Proj611.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
int &fix(int &a);
using namespace::std;
int main(){
	int a=30;
	fix(a)=24;
	cout<<a<<endl;
	return 0;
}

int &fix(int &a){
	if(!cin>>a)
		a=0;
	return a;
}


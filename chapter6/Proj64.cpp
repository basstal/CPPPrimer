/*
 * Proj64.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
int fact();
int main(){
	fact();
	return 0;
}
int fact(){
	cout<<"请输入一个数字"<<endl;
	int val,sum=1;
	cin>>val;
	while(val!=1)
		sum*=val--;
	return sum;
}



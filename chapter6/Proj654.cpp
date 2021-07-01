/*
 * Proj654.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<vector>
#include<iostream>
using namespace::std;
int func1(int,int);
int func2(int,int);
int func3(int,int);
int func4(int,int);
int main(){
	vector<decltype(func1)*> v;
	v.push_back(func1);
	v.push_back(func2);
	v.push_back(func3);
	v.push_back(func4);
	for(auto e:v){
		cout<<e(5,3)<<endl;
	}
	return 0;
}
int func1(int a,int b){
	return a+b;
}
int func2(int a,int b){
	return a-b;
}
int func3(int a,int b){
	return a*b;
}
int func4(int a,int b){
	return a/b;
}



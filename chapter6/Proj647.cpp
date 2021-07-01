/*
 * Proj647.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<vector>
#include<iostream>
#define NDEBUG
using namespace::std;
void print(const vector<int> &);
int main(){
	vector<int> v{1,3,5,7,9};
	print(v);
	return 0;
}
void print(const vector<int> &v){
	if(!v.empty()){
#ifndef NDEBUG
		cout<<"当前vector大小为"<<v.size()<<endl;
#endif
		cout<<v[0]<<" ";
		vector<int> n(v.begin()+1,v.end());
		print(n);
	}
}




/*
 * Proj633.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<vector>
#include<iostream>
using namespace::std;
void print(const vector<int> &);
int main(){
	vector<int> v{1,3,5,7,9};
	print(v);
	return 0;
}
void print(const vector<int> &v){
	if(!v.empty()){
		cout<<v[0]<<" ";
		vector<int> n(v.begin()+1,v.end());
		print(n);
	}
}


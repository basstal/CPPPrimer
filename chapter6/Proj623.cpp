/*
 * Proj623.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
void print(const int);
void print(const int *,size_t);
int main(){
	int i=0,j[2]={0,1};
	print(i);
	print(j,2);
	return 0;
}
void print(const int n){
	cout<<n<<endl;
}
void print(const int * p,size_t s){
	for(int i=0;i!=s;++i)
		cout<<p[i]<<" ";
	cout<<endl;
}



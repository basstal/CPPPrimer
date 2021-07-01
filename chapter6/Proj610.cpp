/*
 * Proj610.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
void exchange(int *,int *);
int main(){
	int a=3,b=5;
	exchange(&a,&b);
	cout<<"a="<<a<<",b="<<b<<endl;
}
void exchange(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}



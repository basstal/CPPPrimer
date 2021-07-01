/*
 * Proj651.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
void f(){
	cout<<"调用f()"<<endl;
}
void f(int a){
	cout<<"调用f(int)"<<endl;
}
void f(int a,int b){
	cout<<"调用f(int,int)"<<endl;
}
void f(double a,double b=3.14){
	cout<<"调用f(double,double)"<<endl;
}
int main(){
//	f(2.56,42);
	f(42);
	f(42,0);
	f(2.56,3.14);
}


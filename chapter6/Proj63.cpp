/*
 * Proj63.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
int fact(int val);
int main(){
	cout<<fact(30)<<endl;
	return 0;

}
int fact(int val){
	if(val==1)
		return 1;
	return val*fact(val-1);
}




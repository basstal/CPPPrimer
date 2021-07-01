/*
 * Proj632.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
int &get(int (&p)[10],int index){
	return p[index];
}

int main(){
	int ia[10];
	for(int i=0;i!=10;++i){
		get(ia,i)=i;
		cout<<ia[i]<<endl;
	}
	return 0;
}




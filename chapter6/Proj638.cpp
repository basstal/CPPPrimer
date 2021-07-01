/*
 * Proj638.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<iostream>
using namespace::std;
int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};
using ref_arr=int [5];
ref_arr (&arrPtr(int i)){
	return (i%2)?odd:even;
}
int main(){
	for(int i=0;i!=5;++i)
		cout<<arrPtr(3)[i]<<" ";
	cout<<endl;
	return 0;
}



/*
 * Proj94.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<vector>
#include<iostream>
using namespace::std;
//bool find(vector<int>::iterator begin,vector<int>::iterator end,int tar);
vector<int>::iterator find(vector<int>::iterator begin,vector<int>::iterator end,int tar);
int main(){
	vector<int> v{2,5,77,18,93,16};
	auto f = find(v.begin(),v.end(),2);
	if(f!=v.end())
		cout<<*f<<endl;
	return 0;
}


//bool find(vector<int>::iterator begin,vector<int>::iterator end,int tar){
//	while(begin!=end)
//		if(*begin++==tar)
//			return true;
//	return false;
//}
vector<int>::iterator find(vector<int>::iterator begin,vector<int>::iterator end,int tar){
	while(begin!=end){
		if(*begin==tar)
			return begin;
		++begin;
	}
	return end;
}



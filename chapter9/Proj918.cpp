/*
 * Proj918.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<string>
#include<deque>
#include<iostream>
#include<list>
using namespace::std;
int main(){
	string s;
	list<string> de;
	while(cin>>s){
		de.push_back(s);
	}
	list<string>::iterator i = de.begin();
	while(i!=de.end()){
		cout<<(*i++)<<" ";
	}
	cout<<endl;

	return 0;
}


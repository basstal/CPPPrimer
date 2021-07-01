/*
 * Proj617.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<cctype>
#include<string>
#include<iostream>
using namespace::std;

bool hasBigC(const string &);
void chagToSmal(string &);
int main(){
	string s="Hopfield";
	chagToSmal(s);
	if(hasBigC(s))
		cout<<"有大写字母"<<endl;
	else
		cout<<"没有大写字母"<<endl;
	return 0;
}
void chagToSmal(string &s){
	for(auto &e:s)
		e=tolower(e);
}

bool hasBigC(const string &s){
	for(auto &e:s)
		if(isupper(e))
			return true;
	return false;
}

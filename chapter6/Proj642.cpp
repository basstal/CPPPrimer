/*
 * Proj642.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include<string>
#include<iostream>
using namespace::std;
string &make_plural(size_t ,string &, const string = "s");
int main(){
	string s="success",f="failure";
	cout<<make_plural(2,s,"es")<<endl;
	cout<<make_plural(2,f)<<endl;
	return 0;
}
string &make_plural(size_t ctr,string &src,const string ending){
	return (ctr>1)?src+=ending:src;
}


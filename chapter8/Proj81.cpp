/*
 * Proj81.cpp
 *
 *  Created on: 2015-1-10
 *      Author: basstal
 */
#include<iostream>
#include<string>
using namespace::std;
istream &func(istream &istr){
//	ofstream ofstr(tofname.c_str(),ios::binary);
//	if(istr.bad())
//		cout << "istr.bad()"<<endl;
//	else if(istr.fail())
//		cout << "istr.fail()" <<endl;
	string s;
	while(!istr.eof()){
		getline(istr,s);
//		cout <<"test";
//		cout <<unitbuf;//没有明显效果
		cout << s;
	}
	istr.clear();
	return istr;
}
int main(){
	func(cin);
	return 0;
}



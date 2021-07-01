/*
 * Proj626.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<string>
#include<iostream>
using namespace::std;
int main(int argc,char **argv){
	string s;
	int n=0;

	while(n!=argc){
		s.append(argv[n++]);
		s.append(" ");
	}
	cout<<s<<endl;
	return 0;
}




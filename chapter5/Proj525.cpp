/*
 * Proj525.cpp
 *
 *  Created on: 2015-1-8
 *      Author: basstal
 */
#include<iostream>
#include<stdexcept>
using namespace::std;
int Proj525()
{
	int ia,ib;

	cin>>ia>>ib;
	try{
		if(ib==0)
			throw runtime_error("除数为0!");
		cout<<ia/ib<<endl;
	}catch(const runtime_error &err){
		cout<<err.what()<<endl;
	}

	return 0;
}




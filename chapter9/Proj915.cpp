/*
 * Proj915.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<vector>
#include<iostream>
#include<list>
using namespace::std;
int main(){
	vector<int> a{1,3,5,7,9};
	vector<int> b{2,4,6,7,42};
	cout<<((a==b)?"a==b":"a!=b")<<endl;

	list<int> c{2,4,6,8,42,66};
	list<int>::iterator ic = c.begin();
	vector<int>::iterator ib = b.begin();
	while(ic!=c.end()&&ib!=b.end()){
		if(*ic!=*ib){
			cout << ((*ic>*ib)?"c>b":"c<b") << endl;
			break;
		}
		++ic;
		++ib;
	}
	if(ib==b.end()&&ic!=c.end())
		cout<<"c>b"<<endl;
	else if(ic==c.end()&&ib!=b.end())
		cout<<"b>c"<<endl;
	return 0;
}



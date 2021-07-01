/*
 * main.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include"Sales_item.h"
#include"support_item.h"
using namespace::std;
int main(){
	Sales_item total;
	if(read(cin,total)){
		Sales_item trans;
		while(read(cin,trans)){
			if(total.getIsbn()==trans.getIsbn()){
				Sales_item tmp=total+trans;
				total.combine(trans);
				cout<<tmp<<endl;
			}
			else{
				print(cout,total)<<endl;
				total=trans;
			}
		}
		print(cout,total)<<endl;
	}
	else{
		cerr<<"没有数据?"<<endl;
	}
	return 0;
}




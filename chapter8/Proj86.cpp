/*
 * main.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include"Sales_item.h"
#include<fstream>
using namespace::std;
int main(int argc,char ** argv){
	if(argc<2)
		return -1;
	string name(argv[1]),base("/home/basstal/"),out(argv[2]);
	ifstream strm(base+name);
	ofstream ostrm(base+out,ofstream::app);
	Sales_item total;
	if(read(strm,total)){
		Sales_item trans;
		while(read(strm,trans)){
			if(total.getIsbn()==trans.getIsbn()){
				Sales_item tmp=total+trans;
				total.combine(trans);
				cout<<tmp<<endl;
			}
			else{
				print(ostrm,total)<<endl;
				total=trans;
			}
		}
		print(ostrm,total)<<endl;
	}
	else{
		cerr<<"没有数据?"<<endl;
	}
	strm.close();
	ostrm.close();
	return 0;
}




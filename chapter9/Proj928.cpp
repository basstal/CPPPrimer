#include<iostream>
#include<forward_list>
#include<string>
using namespace::std;
forward_list<string>::iterator myInsert(forward_list<string> &flist ,const string &src,const string &tar);
int main(){

	forward_list<string> fl{"asdfsdf","fsdafsd","fsdfsdfgdf","fgfgfdgasdf","else","gfdgdfsadfasweqrqwe"};
	myInsert(fl,"else","fine");
	myInsert(fl,"cc","bbysaydf");
	for(const auto &e:fl)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}


forward_list<string>::iterator myInsert(forward_list<string> &flist ,const string &src,const string &tar){
	forward_list<string>::iterator pos = flist.begin();
	forward_list<string>::iterator prev;
	while(pos!=flist.end()){
		if((*pos) == tar){
			pos=flist.insert_after(pos,tar);
			break;
		}
		prev=pos;
		++pos;
	}
	if(pos==flist.end())
		pos = flist.insert_after(prev,tar);
	return pos;
}
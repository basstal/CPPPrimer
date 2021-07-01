#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace::std;

int main(){
	vector<string> svec;
	size_t cnt=0;
	svec.reserve(1024);
	string word;
	ifstream strm("F:\\string.txt");
	if(!strm.is_open())
		cerr<<"open file failed!"<<endl;
	while(strm>>word){
		svec.push_back(word);
		++cnt;
		switch(cnt){
		case 257:cout<<"capacity="<<svec.capacity()<<endl;break;
		case 513:cout<<"capacity="<<svec.capacity()<<endl;break;
		case 1001:cout<<"capacity="<<svec.capacity()<<endl;break;
		case 1049:cout<<"capacity="<<svec.capacity()<<endl;break;
		default:;
		}
	}
	svec.reserve(svec.size()+svec.size()/2);

	return 0;
}
#include"StrBlob.h"
#include<fstream>
#include<iostream>
#include<sstream>
using namespace::std;
int main(){
	ifstream ifs("F:\\string.txt");
	string word,line;
	StrBlob sb;
	while(getline(ifs,line)){
		istringstream iss(line);
		while(iss >> word){
			sb.push_back(word);
		}
		sb.push_back("\n");
	}
	StrBlobPtr sbp = sb.begin();
	while(sbp!=sb.end()){
		cout << sbp.deref() <<endl;
		sbp.incr();
	}
	return 0;
}
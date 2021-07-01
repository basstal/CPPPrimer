/*
 * Proj84.cpp
 *
 *  Created on: 2015-1-10
 *      Author: basstal
 */
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace::std;
vector<string> &readFile(const string &file,vector<string> &src){
	ifstream ifs(file,ifstream::in);
	if(!ifs.is_open())
		cerr<<"open file failed!"<<endl;
	string line,word;
//	while(getline(ifs,line)){
//		src.push_back(line);
//	}

	while(getline(ifs,line)){
			istringstream isstrm(line);
			while(isstrm >> word)
				src.push_back(word);
	}
	ifs.close();
	return src;
}
int main(){
	vector<string> v;
	readFile("/home/basstal/file.txt",v);
//	for_each(v.begin(),v.end(),[](const string &s){cout<<s<<endl;});
	for(const auto &e:v)
		cout<<e<<endl;

	return 0;
}




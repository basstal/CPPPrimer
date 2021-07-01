/*
 * Proj810.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace::std;
int main(){
	vector<string> vec;

	ifstream ifs("/home/basstal/file.txt");
	if(!ifs.is_open()){
		cout << "open file failed!" <<endl;
	}
	string line,word;
	while(getline(ifs,line)){
		vec.push_back(line);
	}
	ifs.close();
	for(int i=0;i!=vec.size();++i){
		istringstream iss(vec[i]);
		while(iss >> word)
			cout << word <<endl;
	}
	return 0;
}




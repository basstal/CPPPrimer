/*
 * Proj811.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace::std;

struct PersonInfo{
	string name;
	vector<string> phones;
	void print()const{
		cout<<name<<": ";
		for(const auto &e:phones)
			cout<<e<<" ";cout<<endl;
	}
};
int main(){
	string line,word;
	vector<PersonInfo> people;
	istringstream record;
	ifstream fstrm("/home/basstal/phone");
	while(getline(fstrm,line)){
		PersonInfo info;
		record.str(line);
		record>>info.name;
		while(record>>word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();//记得将流状态复位!
	}
	fstrm.close();

	for(const auto &ps:people)
		ps.print();
	return 0;
}




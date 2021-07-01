#include<fstream>
#include<string>
#include<map>
#include<sstream>
#include<iterator>
#include<iostream>
#include<unordered_map>
using namespace::std;
using wordmap = unordered_map<string,string>;
wordmap buildMap(istream &istrm);
string transform(const wordmap &m,const string &s);
void word_transform(istream &file,istream &in,ostream &out);
int main(){
	ifstream ifs("F:\\string.txt"),rls("F:\\rules.txt");
	ofstream out("F:\\cout.txt");
	word_transform(rls,ifs,out);
	return 0;
}

wordmap buildMap(istream &istrm){
	wordmap transmap;
	string line;
	while(getline(istrm,line)){
		istringstream iss(line);
		string key,value;
		
		iss>>key;
		while(iss){
			string word;
			iss>>word;
			value+=word+" ";
		}
		if(transmap.find(key)!=transmap.end()){
			cout<<"the transform key "<<key<<" has been inside the map!"<<endl;
			continue;
		}
		transmap.insert({key,value});//s.substr(pos,n)
	}
	return transmap;
}

string transform(const wordmap &m,const string &s){
	auto fd = m.find(s);
	if(fd!=m.end())
		return fd->second;
	else
		return s;
}

void word_transform(istream &rls,istream &in,ostream &out){
	wordmap rules(buildMap(rls));
	string line,word;
#ifndef NDEBUG
	if(!rules.empty())
		for(const auto &e:rules)
			cout<<e.first<<" mapping "<<e.second<<endl;
#endif
	while(getline(in,line)){
		istringstream iss(line);
		while(iss>>word)
			out<<transform(rules,word)<<" ";
		out<<endl;
	}
}

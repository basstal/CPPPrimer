#include<string>
#include<memory>
#include<fstream>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<vector>
#include"StrVec.h"
using namespace::std;
class QueryResult;
class TextQuery{
public:

	TextQuery(ifstream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<StrVec> fileLineCopy;
	map<string,shared_ptr<set<int>>> wordMap;
};
class QueryResult{
	friend ostream& print(ostream & ,const QueryResult);
public:
	set<int>::iterator begin();
	set<int>::iterator	end();
	shared_ptr<StrVec> getfile();
	QueryResult(string s,shared_ptr<StrVec> v,shared_ptr<set<int>> m): str(s),vec(v),ma(m){}
private:
	string str;
	shared_ptr<StrVec> vec;
	shared_ptr<set<int>> ma;
};
shared_ptr<StrVec> QueryResult::getfile(){
	return vec;
}
set<int>::iterator QueryResult::end(){
	return ma->end();
}
set<int>::iterator QueryResult::begin(){
	return ma->begin();
}
QueryResult TextQuery::query(const string &sought) const{
	static shared_ptr<set<int>> nodata(new set<int>);
	auto loc = wordMap.find(sought);
	if(loc == wordMap.end())
		return QueryResult(sought,fileLineCopy,nodata);
	else
		return QueryResult(sought,fileLineCopy,loc->second);
}


TextQuery::TextQuery(ifstream &ifs):fileLineCopy(new StrVec){
	string line;
	while(getline(ifs,line)){
		fileLineCopy->push_back(line);
		istringstream iss(line);
		string word;
		while(iss >> word){
			auto &lines = wordMap[word];
			if(!lines)
				lines.reset(new set<int>);
			lines->insert(fileLineCopy->size()-1);
		}
	}
}


ostream &print(ostream &ostrm,const QueryResult qrst){
	ostrm << qrst.str << " occurs " << qrst.ma->size()<<(qrst.ma->size()>1?" times":" time")<<endl;
	for(auto num : *qrst.ma){
		ostrm << "(line" << num+1 <<")" << (*qrst.vec).at(num)<<endl;
	}
	return ostrm;
}
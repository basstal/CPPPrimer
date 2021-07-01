#include"head.h"
using HOME=map<string,vector<pair<string,string>>>;
void addHome(map<string,vector<pair<string,string>>> &m,const string &newh);
void addChild(HOME &m,const string &h,const string &n);
int main(){

	HOME home;
	addHome(home,"Jack");
	addHome(home,"Tom");
	addChild(home,"Jack","Lim Dam 1991/12/14");
	addChild(home,"Tom","Sindy Japsen 1992/02/27");
	cout << home["Tom"][0].first<<" mapping " << home["Tom"][0].second <<endl;
	return 0;
}

void addHome(HOME &m,const string &newh){
	m[newh];
}

void addChild(HOME &m,const string &h,const string &n){
	size_t pos=0;
	string number("1234567890");
	pos=n.find_first_of(number);
	string pre(n,0,pos),suf(n,pos);
	pair<string,string> p(pre,suf);
	m[h].push_back(p);
}
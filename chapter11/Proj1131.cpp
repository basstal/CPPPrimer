#include"head.h"

using bookWriter=multimap<string,string>;
int main(){
	multimap<string,string> mulMap = {{"john","sicnen"},{"kate","dfjhsfa"},{"peter","leader art"},{"oblivir","killer bil"}};
	auto fd=mulMap.find("jack");
	auto cnt=mulMap.count("jack");
	while(cnt){
		fd = mulMap.erase(fd);
		--cnt;
	}
	for(const auto &e:mulMap)
		cout<<e.first<<" mapping "<<e.second<<endl;
	return 0;
}

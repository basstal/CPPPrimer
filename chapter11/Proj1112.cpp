#include"head.h"
int main(){
	vector<pair<string,int>> vec;
	string s;
	int i;
	while(cin>>s>>i){
//		vec.push_back(make_pair(s,i));
//		vec.push_back({s,i});
		vec.push_back(pair<string,int>(s,i));
	}
	for(const auto &i :vec){
		cout <<i.first << " mapping " << i.second <<endl;
	}
	return 0;
}
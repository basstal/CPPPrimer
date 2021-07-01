#include"head.h"

int main(){
	map<string,size_t> myMap;
	set<string> ignore = {"baba","or","and","by","of"};
	string alpha="abcdefghijklmnopqrstuvwxyz";
	string word;
	size_t pos=0;
	while(cin >> word){
		for(auto &e:word)
			e=tolower(e);
		while((pos = word.find_first_not_of(alpha,pos))!=string::npos)
			word.replace(pos,1,"");
		if(ignore.find(word) == ignore.end())
			++myMap.insert({word,0}).first->second;
		//不允许重复关键字的容器，insert返回pair<iterator指向指定关键字,bool>，允许重复关键字的容器insert返回iterator指向新元素
		pos=0;
	}
	for(auto &w : myMap){
		cout << w.first << " shows " << w.second << (w.second >1? " times":" time") <<endl;
	}
	return 0;
}
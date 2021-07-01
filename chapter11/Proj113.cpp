#include"head.h"

int main(){
	unordered_map<string,size_t> myMap;
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
		pos=0;
	}
	for(auto &w : myMap){
		cout << w.first << " shows " << w.second << (w.second >1? " times":" time") <<endl;
	}
	return 0;
}
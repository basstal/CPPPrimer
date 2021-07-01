#include"head.h"
void elimDups(vector<string> & words);
bool isShorter(const string &s1,const string &s2);
int main(){
	vector<string> words{"fox","jumps","over","quick","red","quick","blow","slow","the","turtle"};
	elimDups(words);
	stable_sort(words.begin(),words.end(),isShorter);
	for(const auto &e:words)
		cout<<e<<" ";
	cout<<endl;

	return 0;
}



bool isShorter(const string &s1,const string &s2){
	return s1.size()>s2.size();
}

void elimDups(vector<string> & words){
	sort(words.begin(),words.end());
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
	auto end_unique = unique(words.begin(),words.end());
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
	words.erase(end_unique,words.end());
	for(const auto &str : words){
		cout << str << "; " ;
	}
	cout << endl;
}
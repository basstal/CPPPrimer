#include"head.h"
bool func(const string &s);
int main(){
	vector<string> words{"fox","jumps","over","quick","red","quick","blow","slow","the","turtle"};
	auto iter = partition(words.begin(),words.end(),func);
	for(const auto &e:words)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}

bool func(const string &s){
	return s.size()>=5;
}
#include"head.h"
void elimDups(list<string> &il);
int main(){
	list<string> words{"fox","jumps","over","quick","red","quick","blow","slow","the","turtle"};
	elimDups(words);
	for(const auto &e:words)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}



void elimDups(list<string> &il){
	il.sort();
	il.unique();
}
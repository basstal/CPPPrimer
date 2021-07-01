#include"head.h"
using namespace::std::placeholders;
bool longer(const string &s,size_t sz);
int main(){
	size_t cnt;
	vector<string> words{"fox","jumps","over","quick","red","quick","blow","slow","the","turtle"};
	cnt = count_if(words.begin(),words.end(),bind(longer,_1,4));
	cout<<"count "<<cnt<<(cnt>1?" times":" time")<<endl;
	return 0;
}

bool longer(const string &s,size_t sz){
	return s.size()>=sz;
}
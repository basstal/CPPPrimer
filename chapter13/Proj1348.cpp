#include"String.h"
#include<vector>
int main(){
	std::vector<String> v;
	v.push_back("abc");
	v.push_back("bcd");
	v.push_back("abc");
	v.push_back("ccc");
	v.push_back("abc");
	v.push_back("bef");
	print(v[0]);
	print(v[3]);
	
	return 0;
}
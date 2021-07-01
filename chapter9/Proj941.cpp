#include"include.h"

int main(){
	
	vector<char> vec_char{'a','e','i','o','u'};
	auto begin=vec_char.begin(),end=vec_char.end();
	string s(&vec_char[0],3);
	cout << s;
	return 0;
}
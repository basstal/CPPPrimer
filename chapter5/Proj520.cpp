#include<string>
#include<iostream>
#include<cctype>
using namespace::std;


int main()
{
	string s,prev;
	cin >> prev;
	while(cin >> s){
		if(s == prev&&isupper(s[0])){
			cout << "重复出现的单词为"<<prev <<endl;
			break;
			
		}
		prev = s;
	}
	if(s!=prev)
		cout << "没有任何单词重复出现" <<endl;

	return 0;
}

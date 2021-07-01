#include<iostream>
#include<string>
using namespace::std;
int main()
{
	string s1,s2;

	do{
		cout<<"请输入两个string对象"<<endl;
		cin>>s1>>s2;
		cout<<"较短的为"<<(s1.size()>s2.size()?s2:s1)<<endl;
	}while(true);
	return 0;
}

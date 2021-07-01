#include<string>
#include<cctype>
#include<iostream>
using namespace::std;
int main()
{
	string text="For the lich king";

	for(auto it=text.begin();it!=text.end();++it)
		*it = toupper(*it); 
	cout<<"text= "<<text<<endl;
	
	return 0;
}

#include<iostream>
#include"StrBlob.h"
int main(){
	StrBlob b1;
	{
		StrBlob b2={"a","an","the"};
		b1=b2;
		b2.push_back("about");
	}
	std::cout<<"b1.size()="<<b1.size();
	return 0;
}
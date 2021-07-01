#include<iostream>
#include<cstring>
int main()
{
	char cs[]="Hello world!";
	char cs1[]="Hello char!";
	
	char cs2[40];
	strcpy(cs2,cs);
	strcat(cs2,cs1);
	std::cout<<cs2;
	return 0;
}

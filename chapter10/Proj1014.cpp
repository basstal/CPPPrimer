#include"head.h"


int main(){
	auto lambda1=[](int a,int b){return a+b;}
	int c;
	auto lambda2=[=](int d){return c+d;}

	return 0;
}
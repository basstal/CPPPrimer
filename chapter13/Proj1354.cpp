#include"HasPtr.h"

int main(){
	HasPtr p1,p2;
	p1=p2;
	p1=std::move(p2);
	return 0;
}
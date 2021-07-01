#include"HasPtr.h"


int main(){
	HasPtr a("HasPtr a"),b("HasPtr b");
	a = b;
	HasPtr c("lala c");
	b = c;
	
	print(a);
	print(b);
	print(c);



	return 0;
}
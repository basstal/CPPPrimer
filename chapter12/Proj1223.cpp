#include"head.h"

int main(){
	string a="aakjdfhi",b="djgkjgdh";
	char * p= link(a,b);
	for(size_t i=0;i<(a.size()+b.size());++i)
		cout<< p[i];

	cout <<endl;
	delete p;
	return 0;
}


char *  link(const string &a,const string &b){
	size_t sz = a.size()+b.size(),i=0;
	char * ch = new char[sz];
	for(auto &w:a)
		ch[i++] = w;
	for(auto &w:b)
		ch[i++] = w;
	return ch;
}
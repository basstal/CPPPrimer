#include"head.h"

int main(){

	string s;
	cin >>s;
	char *p = new char[s.size()];
	for(int i=0;i!=s.size();++i)
		p[i] = s.at(i);
	for(int i =0;i!=s.size();++i){
		cout << p[i];
	}
	cout <<endl;
	delete p;
	return 0;
}
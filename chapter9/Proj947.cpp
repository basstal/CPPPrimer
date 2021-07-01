#include"include.h"

int main(){
	string s("ab2c3d7R4E6");
	string num("0123456789");
	string ch("abcdefghijklmnopqrstuvwxyz");
	int pos=0;
	while((pos = s.find_first_of(num,pos))!=string::npos){
		cout << "index is " << pos << " of " << s[pos] <<endl;
		++pos;
	}
	pos=0;
	while((pos = s.find_first_not_of(num,pos))!=string::npos){
		cout <<" index is "<< pos << " of " <<s[pos] <<endl;
		++pos;
	}
	return 0;
}
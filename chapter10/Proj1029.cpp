

#include"head.h"

int main(){
	ifstream ifs("F:\\string.txt");
	istream_iterator<string> it(ifs),eof;
	vector<string> vec(it,eof);
	ostream_iterator<string> os(cout,"\n");
	copy(vec.begin(),vec.end(),os);
	return 0;
}
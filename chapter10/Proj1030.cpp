#include"head.h"


int main(){
	istream_iterator<int> in(cin),eof;
	ostream_iterator<int> out(cout," ");
	vector<int> v(in,eof);
	sort(v.begin(),v.end());
	unique_copy(v.begin(),v.end(),out);
	return 0;
}

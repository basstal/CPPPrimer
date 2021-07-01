#include"head.h"


int main(){
	list<int> lis{0,4,5,6,7,75,76,7,0,567};
	auto f = find(lis.rbegin(),lis.rend(),0);
	ostream_iterator<int> os_iter(cout," ");
	copy(f.base(),lis.end(),os_iter);
	return 0;
}
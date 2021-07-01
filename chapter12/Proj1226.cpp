#include"head.h"

int main(){
	size_t n=30;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	string *q=p;
	while(cin>>s&&q!=p+n)
		alloc.construct(q++,s);
	while(q!=p)
		alloc.destroy(--q);
	alloc.deallocate(p,n);
	return 0;
}
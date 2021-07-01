#include"Foo.h"


int main(){
	std::vector<int> v{25,7,32,6,44,9,12,18};
	Foo f1(v);
	f1.sorted();

	return 0;
}

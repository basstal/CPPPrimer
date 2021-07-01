
#include"HasPtr05.h"

bool fcn(const HasPtr *p1, HasPtr p2);

int main(void) {
	HasPtr hp,hp1;
	fcn(&hp, hp);
	std::cout << "after main" << std::endl;
	return 0;
}


bool fcn(const HasPtr *p1, HasPtr p2) {
	HasPtr hpt1(*p1), hpt2(p2);

	return true;
}
#include "StrBlob.h"
#include <iostream>

int main(void) {


	StrBlob sb1;
	
	StrBlob sb2;

	sb2 = sb1;

	std::cout << sb2.data.use_count() << std::endl;
	return 0;
}

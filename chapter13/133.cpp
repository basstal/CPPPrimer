#include "StrBlob.h"
#include <iostream>

int main(void) {
	//std::vector<std::string> v1(10);


	StrBlob sb({"haha","haha1","haha2"});

	StrBlob sb1 = sb;

	StrBlobPtr sbp1(sb1);

	StrBlobPtr sbp2 = sbp1;

	std::cout << "eq(sbp2,sbp1) "<<eq(sbp2, sbp1)<<std::endl;
	return 0;

}
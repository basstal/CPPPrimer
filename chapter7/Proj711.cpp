/*
 * Proj711.cpp
 *
 *  Created on: 2015-1-10
 *      Author: basstal
 */
#include"Sales_item.h"

int main(){
	Sales_item si1(),si2("New World",3,25.5),si3(si2),si4(std::cin);
	std::cout<<"si1 "<<si1<<" ,si2 "<<si2<<" ,si3 "<<si3<<" ,si4 "<<si4<<std::endl;
	return 0;
}




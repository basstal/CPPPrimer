/*
 * support_item.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include"support_item.h"

std::istream &read(std::istream &ism,Sales_item &s){
	std::cout<<"请按照ISBN、售出数量、售出价格的顺序输入数据（中间用空格隔开）"<<std::endl;
	return ism>>s;
}

std::ostream &print(std::ostream &osm,const Sales_item &s){
	return osm<<s;
}

Sales_item add(Sales_item &s1,const Sales_item &s2){
	return s1+s2;
}




/*
 * support_item.h
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */

#ifndef SUPPORT_ITEM_H_
#define SUPPORT_ITEM_H_
#include"Sales_item.h"
std::istream &read(std::istream &,Sales_item &);
std::ostream &print(std::ostream &,const Sales_item &);
Sales_item add(Sales_item &,const Sales_item &);


#endif /* SUPPORT_ITEM_H_ */


/*
 * Sales_item.cpp
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */
#include "Sales_item.h"

Sales_item &Sales_item::combine(const Sales_item &s){
		soldBok+=s.getSoldBok();
		mount+=s.getMount();
		return *this;
}
bool compareIsbn(const Sales_item &s1,const Sales_item &s2){
	return s1.getIsbn()>s2.getIsbn();
}
std::istream & operator>>(std::istream& istm,Sales_item& si)
{
	std::string tmps;
	int tmpi;
	double tmpd;
	istm >> tmps;
	si.setIsbn(tmps);
	istm >> tmpi;
	si.setSoldBok(tmpi);
	istm >> tmpd;
	si.setPrice(tmpd);
	si.setMount(tmpi*tmpd);

	return istm;
}
std::ostream & operator<<(std::ostream& ostm,const Sales_item & si)
{
	ostm << "ISBN - "<<si.getIsbn() << " Price= "<<si.getPrice()<<" soldBok= "<<si.getSoldBok()<<" Mount= "<<si.getMount();

	return ostm;

}
Sales_item & Sales_item::operator=(const Sales_item &si)
{
	ISBN = si.getIsbn();
	price = si.getPrice();
	mount = si.getMount();
	soldBok=si.getSoldBok();
	return *this;
}
Sales_item Sales_item::operator+(const Sales_item &si)const
{
	Sales_item tmp(*this);
	if(ISBN !=si.getIsbn()||ISBN == "empty"||si.getIsbn() == "empty")
	{
		std::cout<<"ISBN not equal!"<<std::endl;
		return tmp;
	}
	if(price!=si.getPrice())
	{
		std::cout<<"price not equal!"<<std::endl;
		return tmp;
	}
	tmp.setSoldBok(this->getSoldBok()+si.getSoldBok());
	tmp.setMount(this->getMount()+si.getMount());
	return tmp;
}
Sales_item & Sales_item::operator+=(Sales_item & si)
{
	this->operator+(si);
	return *this;
}

Sales_item::~Sales_item(void)
{
}
std::istream &read(std::istream &ism,Sales_item &s){
	std::cout<<"Please input ISBN soldBok price"<<std::endl;
	return ism>>s;
}

std::ostream &print(std::ostream &osm,const Sales_item &s){
	return osm<<s;
}

Sales_item add(Sales_item &s1,const Sales_item &s2){
	return s1+s2;
}





/*
 * Sales_item.h
 *
 *  Created on: 2015-1-9
 *      Author: basstal
 */

#ifndef SALES_ITEM_H_
#define SALES_ITEM_H_
#include<string>
#include<iostream>
class Sales_item
{
friend std::istream & operator>>(std::istream&,Sales_item&);
friend std::ostream & operator<<(std::ostream&,const Sales_item &);
private:
	std::string ISBN;
	int soldBok;
	double mount;
	double price;

public:
	Sales_item(const Sales_item &si):Sales_item(si.getIsbn(),si.getSoldBok(),si.getPrice()){}
	Sales_item(std::istream &istrm){read(istrm,*this);}
	Sales_item():Sales_item("",0,0){}
	Sales_item(std::string str,int sb,double p):ISBN(str),soldBok(sb),price(p),mount(p*sb){}

	int getSoldBok(void)const{return soldBok;}
	double getPrice(void)const{return price;}
	double getMount(void)const{return mount;}

	Sales_item &combine(const Sales_item &s);
	Sales_item & operator=(const Sales_item &);
	Sales_item operator+(const Sales_item &)const;
	Sales_item & operator+=(Sales_item &);

	~Sales_item(void);

	std::string getIsbn() const {
		return ISBN;
	}

	void setIsbn(std::string isbn) {
		ISBN = isbn;
	}

	void setMount(double mount) {
		this->mount = mount;
	}

	void setPrice(double price) {
		this->price = price;
	}

	void setSoldBok(int soldBok) {
		this->soldBok = soldBok;
	}
};
std::istream &read(std::istream &,Sales_item &);
std::ostream &print(std::ostream &,const Sales_item &);
Sales_item add(Sales_item &,const Sales_item &);



#endif /* SALES_ITEM_H_ */


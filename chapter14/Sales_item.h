#pragma once
#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include<string>
#include<iostream>
class Sales_item
{
friend std::istream &operator>>(std::istream &is,const Sales_item &s);
friend std::ostream &operator<<(std::ostream &os,const Sales_item &s);
friend Sales_item operator+(const Sales_item &lhs,const Sales_item &rhs);
private:
	std::string ISBN;
	int soldBok;
	double mount;
	double price;
	
public:
	Sales_item(std::string str,int sb,double m,double p):ISBN(str),soldBok(sb),mount(m),price(p){}
	std::string & isbn(void);

	Sales_item &operator=(const string &);
	Sales_item & operator=(const Sales_item &);
	Sales_item &operator+=(const Sales_item &);
	Sales_item(const Sales_item &);
	Sales_item(void);
	~Sales_item(void);
};

std::istream &operator>>(std::istream &is,const Sales_item &s);
std::ostream &operator<<(std::ostream &os,const Sales_item &s);
Sales_item operator+(const Sales_item &lhs,const Sales_item &rhs);
#endif

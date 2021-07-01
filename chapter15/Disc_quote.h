#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"
class Disc_quote : public Quote
{
public:
	Disc_quote(){std::cout<<"Disc_quote()"<<std::endl;}
	Disc_quote(const std::string &bookNo,double price,std::size_t quantity,double discount):Quote(bookNo,price),qty(quantity),disc(discount)
	{
		std::cout<<"Disc_quote(const std::string &bookNo,double price,std::size_t quantity,double discount)"<<std::endl;
	}
	Disc_quote(const Disc_quote &rhs):Quote(rhs)
	{
		if(this != &rhs)
		{
			qty = rhs.qty;
			disc = rhs.disc;
		}
		std::cout<<"Disc_quote(const Disc_quote &rhs)"<<std::endl;
	}
	Disc_quote &operator=(const Disc_quote &rhs)
	{
		Quote::operator=(rhs);
		if(this != &rhs)
		{
			qty = rhs.qty;
			disc = rhs.disc;
		}
		std::cout<<"Disc_quote &operator=(const Disc_quote &rhs)"<<std::endl;
		return *this;
	}

	virtual ~Disc_quote()
	{
		std::cout<<"virtual ~Disc_quote()"<<std::endl;
	}
	virtual double net_price(std::size_t quantity) const override = 0;
protected:
	std::size_t qty;
	double disc;
};

#endif
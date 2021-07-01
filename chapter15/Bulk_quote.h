#ifndef _BULK_QUOTE_H_
#define _BULK_QUOTE_H_
#include "Disc_quote.h"
class Bulk_quote:public Disc_quote{
public:
	// Bulk_quote(){std::cout<<"Bulk_quote()"<<std::endl;}
	// Bulk_quote(const std::string &bookIsbn,double salesPrice,std::size_t quota,double dct):Disc_quote(bookIsbn,salesPrice,quota,dct)
	// {
	// 	std::cout<<"Bulk_quote(const std::string &bookIsbn,double salesPrice,std::size_t quota,double dct)"<<std::endl;
	// }
	// Bulk_quote(const Bulk_quote &rhs):Disc_quote(rhs)
	// {
	// 	std::cout<<"Bulk_quote(const Bulk_quote &rhs)"<<std::endl;
	// }
	using Disc_quote::Disc_quote;
	Bulk_quote &operator=(const Bulk_quote &rhs)
	{
		Disc_quote::operator=(rhs);
		std::cout<<"Bulk_quote &operator=(const Bulk_quote &rhs)"<<std::endl;
	}

	virtual ~Bulk_quote()
	{
		std::cout<<"virtual ~Bulk_quote()"<<std::endl;
	}

	virtual Bulk_quote *clone() const &{return new Bulk_quote(*this);}
	virtual Bulk_quote *clone() && {return new Bulk_quote(std::move(*this));}
	virtual double net_price(size_t quantity) const override
	{
		return quantity * price * (quantity>qty?1-disc:1);
	}
	virtual void debug() const override;
};

void Bulk_quote::debug() const
{
	Quote::debug();
    std::cout << "min_qty= " << this->qty << " "
              << "discount= " << this->disc<< " ";
}

#endif
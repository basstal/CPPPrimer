#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <string>
class Basket;
class Quote{
	friend class Basket;
public:
	Quote()
	{
		std::cout<<"Quote()"<<std::endl;
	}
	Quote(const std::string &bookIsbn,double salesPrice):isbn(bookIsbn),price(salesPrice)
	{std::cout<<"Quote(const std::string &bookIsbn,double salesPrice)"<<std::endl;}
	Quote(const Quote &rhs)
	{
		if(this != &rhs)
		{
			isbn = rhs.isbn;
			price = rhs.price;
		}
		std::cout<<"Quote(const Quote &rhs)"<<std::endl;
	}
	Quote &operator=(const Quote &rhs)
	{
		if(this != &rhs)
		{
			isbn = rhs.isbn;
			price = rhs.price;
		}
		std::cout<<"Quote &operator=(const Quote &rhs)"<<std::endl;
		return *this;
	}
	virtual ~Quote()
	{
		std::cout<<"virtual ~Quote()"<<std::endl;
	}

	virtual Quote *clone() const &{return new Quote(*this);}
	virtual Quote *clone() &&{return new Quote(std::move(*this));}
	
	virtual void debug() const;
	

	std::string getIsbn() const {return isbn;}
	void setIsbn(const std::string &isbn) {this->isbn = isbn;}
	virtual double net_price(size_t quantity) const {return quantity*price;}
private:
	std::string isbn;
protected:
	double price = 0.0;
};
void Quote::debug() const
{
    std::cout << "data members of this class:\n"
              << "bookNo= " <<this->isbn << " "
              << "price= " <<this->price<< " ";
}

#endif
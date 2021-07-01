#ifndef BASKET_H
#define BASKET_H
#include "Quote.h"
#include <set>
#include <memory>
#include <iostream>
int print_total(std::ostream &os,const Quote &q,const int n);
class Basket
{

public:
	void add_items(const Quote &q){m.insert(std::shared_ptr<Quote>(q.clone()));}
	void add_items(Quote &&q){m.insert(std::shared_ptr<Quote>(std::move(q).clone()));}

	double total_receipt(std::ostream &os)const;

private:
	static bool compare(const std::shared_ptr<Quote> &a,const std::shared_ptr<Quote> &b)
	{
		return a->getIsbn() < b->getIsbn();
	}

	std::multiset<std::shared_ptr<Quote>,decltype(compare)*> m{compare};
};

double Basket::total_receipt(std::ostream &os)const
{
	double sum = 0;
	for(auto iter = m.cbegin(); iter != m.cend() ; iter = m.upper_bound(*iter))
	{
		
		sum += print_total(os,**iter,m.count(*iter));
	}
	os<<"Total Sales :"<<sum <<std::endl;
	return sum;
}


#endif 
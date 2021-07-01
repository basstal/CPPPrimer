#include "Quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
#include "Disc_quote.h"
#include <iostream>
#include "Basket.h"
int print_total(std::ostream &os,const Quote &q,const int n)
{
	os<<" n : "<<n<<", cost : "<<q.net_price(n)<<std::endl;
	return q.net_price(n);
}

int main()
{
	Basket bkt;
	bkt.add_items(Quote("isbn3",5));
	bkt.add_items(Quote("isbn3",5));
	bkt.add_items(Quote("isbn5",5));
	bkt.add_items(Quote("isbn8",5));
	bkt.add_items(Bulk_quote("isbn6",7,3,0.3));
	bkt.add_items(Bulk_quote("isbn4",12,7,0.2));
	bkt.add_items(Bulk_quote("isbn4",15,7,0.2));
	bkt.add_items(Bulk_quote("isbn2",18,12,0.1));
	bkt.add_items(Bulk_quote("isbn1",9,6,0.1));
	std::cout<<"sum : "<<bkt.total_receipt(std::cout)<<std::endl;
	return 0;
}
#ifndef _LIMIT_QUOTE_H_
#define _LIMIT_QUOTE_H_

#include"Disc_quote.h"


class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const std::string& b, double p, std::size_t max, double disc):Disc_quote(b,p,max,disc)   {   }
    virtual ~Limit_quote() = default;
    virtual double net_price(std::size_t n) const override
    { 
    	double sum = 0;
    	if(n>qty){
    		sum+= (qty * (1-disc) + n-qty) * price;
    	}else{
    		sum += n * price *(1-disc);
    	}
    	return sum;
    }
    virtual void debug() const;
};
void Limit_quote::debug() const
{
	Quote::debug();
    std::cout << "max_qty= " << this->qty << " "
              << "discount= " << this->disc<< " ";
}
#endif // !_LIMIT_QUOTE_H_


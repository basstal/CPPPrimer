#include <vector>
#include <iostream>
#include <memory>
#include "Quote.h"
#include "Bulk_quote.h"
using namespace std;
int main()
{
	vector<shared_ptr<Quote>> v;
	v.push_back(make_shared<Bulk_quote>("isbn1",5,3,0.2));
	v.push_back(make_shared<Bulk_quote>("isbn2",7,5,0.2));
	v.push_back(make_shared<Bulk_quote>("isbn3",10,7,0.2));
	double sum = 0;
	for(vector<shared_ptr<Quote>>::iterator it = v.begin(); it != v.end() ; ++it)
	{
		sum += (*it)->net_price(5);
	}
	cout<<sum<<endl;
	sum = 0;
	vector<Quote> v1;
	v1.push_back(Bulk_quote("isbn1",5,3,0.2));
	v1.push_back(Bulk_quote("isbn2",7,5,0.2));
	v1.push_back(Bulk_quote("isbn3",10,7,0.2));
	for(vector<Quote>::iterator it = v1.begin(); it != v1.end() ; ++it)
	{
		sum += (*it).net_price(5);
	}
	cout<<sum<<endl;
	return 0;
}
#include"Sales_item.h"
//---------------------------------public function--------------------------------
Sales_item &Sales_item::operator=(const string &s){
	this->ISBN=s;
	return *this;
}
std::string & Sales_item::isbn(void)
{
	return ISBN;
}
std::istream & operator>>(std::istream& istm,const Sales_item& si)
{
	istm >> si.ISBN>>si.soldBok>> si.price;
	if(istm)
		si.mount = si.price*si.soldBok;
	else
		si=Sales_item();
	return istm;
}

std::ostream & operator<<(std::ostream& ostm,const Sales_item & si)
{
	ostm << "ISBN - "<<si.ISBN << " Price= "<<si.price<<" soldBok= "<<si.soldBok<<" Mount= "<<si.mount;

	return ostm;
	
}
Sales_item & Sales_item::operator=(const Sales_item &si)
{
	ISBN = si.ISBN;
	price = si.price;
	mount = si.mount;
	soldBok=si.soldBok;
	return *this;
}

Sales_item & Sales_item::operator+=(const Sales_item & si)
{
	return operator+(*this,si);
}
Sales_item::Sales_item(const Sales_item & si):ISBN(si.ISBN),price(si.price),mount(si.mount),soldBok(si.soldBok){}
Sales_item::Sales_item(void)
{
	ISBN = "empty";
	price=0;
	mount=0;
	soldBok=0;
}


Sales_item::~Sales_item(void)
{
}
//---------------------------------------friend function------------------------------------
Sales_item operator+(const Sales_item &s1,const Sales_item &s2){
	auto tmp=s1;
	if(tmp.ISBN !=s2.ISBN||tmp.ISBN == "empty"||s2.ISBN == "empty")
		throw runtime_error("ISBN not equal!");
	if(tmp.price!=s2.price)
		throw runtime_error("price not equal!");
	tmp.soldBok +=s2.soldBok;
	tmp.mount +=s2.mount;
	return tmp;
}
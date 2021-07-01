#include "Bulk_quote.h"
using namespace std;
int main()
{
	Quote q1;//Quote()
	Quote *q2 = new Quote("test",1.0);
	q1.debug();
	q2->debug();
	cout<<endl;
	Quote q6("isbn1",5.5);//Quote(const std::string &bookIsbn,double salesPrice)
	cout<<endl;
	//Disc_quote d1;//Quote()\nDisc_quote()
	//cout<<endl;
	Bulk_quote b1;//Quote()\nDisc_quote()\nBulk_quote()
	cout<<endl;

	Quote *pq2 = new Bulk_quote;//Quote()\nDisc_quote()\nBulk_quote()
	cout<<endl;
	//Quote *pq3 = new Disc_quote;//Quote()\nDisc_quote()
	//cout<<endl;
	Disc_quote *pb2 = new Bulk_quote;//Quote()\nDisc_quote()\nBulk_quote()
	cout<<endl;
	Quote q4(b1);//Quote(const Quote &rhs)
	cout<<endl;
	//Quote q5(d1);//Quote(const Quote &rhs)
	//cout<<endl;
	Bulk_quote b3(b1);//Quote(const Quote &rhs)\nDisc_quote(const Disc_quote &rhs)\nBulk_quote(const Bulk_quote &rhs)
	cout<<endl;
	q1 = b3;//Quote &operator=(const Quote &rhs)
	cout<<endl;
	b1 = b3;//Quote &operator=(const Quote &rhs)\nDisc_quote &operator=(const Disc_quote &rhs)\nBulk_quote &operator=(const Bulk_quote &rhs)

	delete pq2;
	delete pb2;
	delete q2;
	return 0;
}
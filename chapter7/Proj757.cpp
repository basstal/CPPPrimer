/*
 * Proj757.cpp
 *
 *  Created on: 2015-1-10
 *      Author: basstal
 */
class Account{
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period =30;
	double daily_tbl[period];
public:
	void calculate(){amount+=amount*interestRate;}
	static double rate(){return interestRate;}
	static void rate(double);
};
void Account::rate(double newRate){
	interestRate=newRate;
}
double Account::initRate(){
	return 0;
}
double Account::interestRate = initRate();
constexpr int Account::period;

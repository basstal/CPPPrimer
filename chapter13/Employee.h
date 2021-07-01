class Employee{
public:
	Employee():name("") ,ID(0){}
	Employee(const string & s):name(s),ID(incr++){}
private:
	static int incr=1;
	std::string name;
	int ID;
};

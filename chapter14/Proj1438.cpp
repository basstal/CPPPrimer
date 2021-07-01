
#include<string>
#include<iostream>
#include<vector>
#include<fstream>


class BoundTest
{
public:
	BoundTest(std::size_t l=0,std::size_t u=0):lower(l),upper(u){}
	bool operator()(const std::string &res)
	{
		return res.length()>=lower;
			//&&res.length()<=upper);
	}

private:
	std::size_t lower,upper;

};


int main()
{
	std::size_t l=10;
	std::string s;
	BoundTest test(l);
	std::ifstream ifs("s.txt");
	std::size_t quantity=0;

	while(ifs>>s)
	{
		if(test(s))++quantity;
	}
	std::cout<<"quantity = " << quantity<<std::endl;
	return 0;
}

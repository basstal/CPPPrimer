#include <iostream>
#include <string>
#include <vector>

class ReadString
{
public:
	ReadString(std::istream &is = std::cin) : i(is) {} 
	std::string operator()(void) const
	{
		std::string s;
		getline(i,s);
		
		if(i.bad()) return "";
		
		return s;
	}
	
private:
	
	std::istream &i;
};



int main()
{
	ReadString rs;
	std::vector<std::string> vec;
	for(int i=0;i<5;++i)
		vec.push_back(rs());
	for(const auto u : vec)
		std::cout << u <<std::endl;

	return 0;
}



#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class EqualAndReplace
{
public:
	EqualAndReplace(const std::string &r = "",const std::string &n = ""):reference(r),newValue(n){}
	void operator()(std::string &check)
	{
		if(check == reference) check = newValue;
	}

private:
	std::string reference,newValue;
};

int main()
{
	std::vector<std::string> v = {"alan","alan","alan","alan","wang","wang","wang","wang"};

	for(const auto &s : v)
		std::cout << s << "\n";

	for_each(v.begin(), v.end(), EqualAndReplace("alan","moophy"));

	std::cout << "\n";
	for(const auto &s : v)
		std::cout << s << "\n";

	return 0;
}



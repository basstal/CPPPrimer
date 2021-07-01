#include"Sales_item.h"
#include<fstream>
#include<vector>
#include<map>
#include<sstream>
int S_i_D()
{
	std::ifstream ifsm("E:\\ÎÄµµ¿â\\Txt\\Sales_item.txt");
	std::string line;
	std::vector<Sales_item> vcSi;
	std::map<std::string,int> ocurTimes;
	while(getline(ifsm,line))
	{
		std::istringstream iss(line);
		Sales_item tmp;
		iss >> tmp;
		++ocurTimes[tmp.isbn()];
		vcSi.push_back(tmp);
	}
	auto prev = vcSi.begin();
	Sales_item siSum(*prev);
	for(auto i = vcSi.begin();i!=vcSi.end();++i)
	{
		std::cout << *i << std::endl;
		if(prev!=i&&i->isbn() == prev->isbn())
			siSum+=*i;
		prev=i;
	}
	std::cout <<siSum << std::endl;
	for(auto i=ocurTimes.begin();i!=ocurTimes.end();++i)
		std::cout << i->first << " occurs " << i->second <<" times" <<std::endl;
	system("pause");
	return 0;
}


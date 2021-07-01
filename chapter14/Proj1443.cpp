

#include<vector>
#include<iostream>
#include<algorithm>


int main()
{
	int i = 1024;
	bool flag = true;
	std::vector<int> vec = {
		2,8,17
	};
	std::modulus<int> mod;
	for(auto e:vec)
	{
		if(mod(i,e) != 0)flag = false;
	}
	std::cout<< (flag?"true":"false") <<"\n";
	return 0;


}

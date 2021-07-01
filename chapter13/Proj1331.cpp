#include"HasPtr.h"
#include<functional>
#include<vector>
#include<algorithm>
using namespace::std;
using namespace::std::placeholders;
int main(){
	vector<HasPtr> v;
	v.push_back(HasPtr("you know what"));
	print(v[0]);
	v.push_back(HasPtr("i guess"));
	print(v[1]);

	v.push_back(HasPtr("fool of you"));
	print(v[2]);

	v.push_back(HasPtr("deal with"));
	print(v[3]);

	v.push_back(HasPtr("you wish is mine"));
	print(v[4]);
	std::cout << "begin sort " << std::endl;
	//sort(v.begin(),v.end(),bind(oprt_less,_2,_1));
	sort(v.begin(), v.end());
	for (auto vt : v) {
		print(vt);
	}
	std::cout << "sort end" << std::endl;
	return 0;
}
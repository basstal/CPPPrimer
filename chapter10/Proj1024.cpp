#include"head.h"
using namespace::std::placeholders;
bool check_size(const string &s,size_t sz);
int main(){

	vector<int> vec{4,7,22,5,434};
	auto myCheck = bind(check_size,"longlonglong",_1);
	for(const auto &e:vec)
		if(myCheck(e)){
			cout <<"The first is "<<e<<endl;
			break;
		}
	return 0;
}

bool check_size(const string &s,size_t sz){
	return s.size()<=sz;
}
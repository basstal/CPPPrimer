#include"include.h"

int main(){

	vector<string> vec{"100.25","222.73","333.11"};
	double sum=0;
	for(auto &e:vec)
		sum+=atof(e.c_str());
	cout<<sum<<endl;
	return 0;
}
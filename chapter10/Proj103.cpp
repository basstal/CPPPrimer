#include"head.h"


int main(){
	vector<double> vec{123,5,345,43,53,454,35,345,34,532,43,5,345,34,5};
	double sum = accumulate(vec.cbegin(),vec.cend(),0) ;
	cout << sum << " "<<endl;
	fill_n(vec.begin(),vec.size(),0);
	sum = accumulate(vec.begin(),vec.end(),0);
	cout << sum <<endl;
	return 0;
}
#include <iostream>
#include <vector>
using namespace::std;
class Sales_data{
};
template<typename T>
int compare(const T &t1,const T &t2)
{
	if(t1<t2)return -1;
	if(t2<t1)return 1;
	return 0;
}


int main()
{
	//Sales_data s1,s2;
	cout<< compare(1,0) <<endl;
	
	vector<int> vec1{1,3,5},vec2{2,4,7};
	cout<< compare(vec1,vec2) <<endl;
	//cout<< compare(s1,s2) <<endl;
	return 0;
}
#include<vector>
#include<iostream>
using namespace::std;
int main(){
	vector<int> vec{123,5,345,43,53,454,35,345,34,532,43,5,345,34,5};

	cout << count(vec.begin(),vec.end(),5) << endl;
	return 0;
}
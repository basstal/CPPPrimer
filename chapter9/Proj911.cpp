/*
 * Proj911.cpp
 *
 *  Created on: 2015-1-11
 *      Author: basstal
 */
#include<vector>
using namespace::std;
int main(){
	vector<int> v1;
	vector<int> v2{1,3,5};
	vector<int> v3(10);
	vector<int> v4(10,5);
	vector<int> v5(v2);
	vector<int> v6(v2.begin(),v2.end());//最关键的一种
	return 0;
}



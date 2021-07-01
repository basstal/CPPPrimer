#include<vector>
#include<string>
#include<iostream>
using namespace::std;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,42);
	vector<int> v4{10};
	vector<int> v5{10,42};
	vector<string> v6{10};
	vector<string> v7{10,"hi"};

	size_t cnt=0;
	cout<<"v1"<<endl;
	for(auto it = v1.begin();it!=v1.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	cnt=0;
	cout<<"v2"<<endl;
	for(auto it = v2.begin();it!=v2.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	cnt=0;
	cout<<"v3"<<endl;
	for(auto it = v3.begin();it!=v3.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	cnt=0;
	cout<<"v4"<<endl;
	for(auto it = v4.begin();it!=v4.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	cnt=0;
	cout<<"v5"<<endl;
	for(auto it = v5.begin();it!=v5.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	cnt=0;
	cout<<"v6"<<endl;
	for(auto it = v6.begin();it!=v6.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	cnt=0;
	cout<<"v7"<<endl;
	for(auto it = v7.begin();it!=v7.end();++it,++cnt)
		cout<<*it<<endl;
	cout<<cnt<<endl;
	return 0;
}

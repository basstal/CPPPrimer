#include<vector>
#include<string>
#include<iostream>
using namespace::std;

int main(){
	vector<int> ts;

	cout<<"capacity="<<ts.capacity()<<",size="<<ts.size()<<endl;
	cout<<"after add one element\n";
	ts.push_back(1);
	cout<<"capacity="<<ts.capacity()<<",size="<<ts.size()<<endl;
	cout<<"continue add more elements\n";
	for(int i=0;i!=12;++i){
		ts.push_back(1);
		cout<<"capacity="<<ts.capacity()<<",size="<<ts.size()<<endl;
	}
	return 0;
}
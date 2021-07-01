#include"HasPtr.h"
#include<vector>
using namespace::std;
HasPtr foo_bar(HasPtr arg,const HasPtr &quote);
HasPtr global;
int main(){
	foo_bar(global,global);
	cout<<"foo_bar(global,global);"<<endl;
	vector<HasPtr> v;
	cout<<"vector<HasPtr> v;"<<endl;
	v.push_back(global);
	cout<<"v.push_back(global);"<<endl;
	return 0;
}



HasPtr foo_bar(HasPtr arg,const HasPtr &quote){
	cout<<"begin"<<endl;
	HasPtr local, *heap = new HasPtr(global);
	cout<<"HasPtr local, *heap = new HasPtr(global);"<<endl;
	local=arg;
	cout<<"local=arg;"<<endl;
	*heap=local;
	cout<<"*heap=local;"<<endl;
	HasPtr pa[4]={local,*heap};
	cout<<"HasPtr pa[4]={local,*heap};"<<endl;
	return *heap;
}